#include "Application.hpp"

namespace px {
	Application::Application() {
	}

	void Application::init() {
		modulesHolder.init<Window>(1280u, 720u, "ProjectX");
		modulesHolder.init<Renderer>();
		auto& window = modulesHolder.get<Window>();
		auto& renderer = modulesHolder.get<Renderer>();
		while (window.isOpen()) {
			window.tempUpdate();

			update();

			renderer.clear();

			display();
			
			window.clear();
			renderer.display();
			window.display();
		}

	}
	void Application::display() {

	}
	void Application::update() {

	}
}
