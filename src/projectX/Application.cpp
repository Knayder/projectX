#include "Application.hpp"

namespace px {
	Application::Application() {
	}

	void Application::init() {
		modulesHolder.init<Window>(1280u, 720u, "ProjectX");
		auto& window = modulesHolder.get<Window>();
		while (window.isOpen()) {
			window.tempUpdate();
			window.clear();
			window.display();
		}

	}
}
