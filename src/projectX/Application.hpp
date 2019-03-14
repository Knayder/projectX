#pragma once

#include <SFML/Graphics.hpp>

#include "utility/ModulesHolder.hpp"

#include "modules/window/Window.hpp"

namespace px {

	class Application {
	public:
		Application();

		void init();

	private:
		ModulesHolder<Window> modulesHolder;
	};

}