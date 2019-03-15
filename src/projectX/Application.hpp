#pragma once

#include <SFML/Graphics.hpp>

#include "projectX/utility/ModulesHolder.hpp"

#include "projectX/modules/window/Window.hpp"

namespace px {

	class Application {
	public:
		Application();

		void init();

	private:
		ModulesHolder<Window> modulesHolder;
	};

}