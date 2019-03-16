#pragma once

#include "projectX/modules/window/Window.hpp"
#include "projectX/utility/Module.hpp"

namespace px {
	class Input : public Module<Window> {
	public:
		Input();

		void init();

		void update();
	};
}