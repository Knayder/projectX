#pragma once

#include <SFML/Graphics.hpp>

#include "projectX/utility/ModulesHolder.hpp"

#include "projectX/modules/window/Window.hpp"
#include "projectX/modules/renderer/Renderer.hpp"

namespace px {

	class Application {
	public:
		Application();

		void init();

		void display();

		void update();

	private:
		ModulesHolder<Window, Renderer> modulesHolder;
	};

}