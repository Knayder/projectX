#pragma once

#include <SFML/Graphics.hpp>

#include "projectX/utility/ModulesHolder.hpp"

#include "projectX/modules/window/Window.hpp"
#include "projectX/modules/renderer/Renderer.hpp"
#include "projectX/modules/world/World.hpp"

namespace px {

	class Application {
	public:
		Application();

		void init();

		void input(const sf::Event& event);

		void display();

		void update(float deltaTime);

	private:
		ModulesHolder<Window, Renderer, World> modulesHolder;
	};

}