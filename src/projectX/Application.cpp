#include "Application.hpp"

namespace px {
	Application::Application() {
	}

	void Application::init() {
		modulesHolder.init<Window>(1280u, 720u, "ProjectX");
		modulesHolder.init<Renderer>();
		modulesHolder.init<World>();
		auto& window = modulesHolder.get<Window>();
		auto& renderer = modulesHolder.get<Renderer>();

		sf::Clock clock;
		float deltaTime = 1.f / 60.f;

		while (window.isOpen()) {
			deltaTime = clock.restart().asSeconds();

			sf::Event event;
			while (window.pollEvent(event)) {
				window.input(event);
				input(event);
			}

			update(deltaTime);

			renderer.clear();

			display();
			
			window.clear();
			renderer.display();
			window.display();
		}

	}
	void Application::input(const sf::Event& event) {
		//modulesHolder.get<module>().input(event);
		modulesHolder.get<World>().input(event);
	}

	void Application::display() {
		//modulesHolder.get<module>().draw();
		modulesHolder.get<World>().draw();
	}

	void Application::update(float deltaTime) {
		//modulesHolder.get<module>().update(deltaTime);
		modulesHolder.get<World>().update(deltaTime);
	}
}
