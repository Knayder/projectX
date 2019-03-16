#pragma once

#include <SFML/Graphics.hpp>
#include <array>

namespace px {
	class InputData {
	public:
		using Keyboard = sf::Keyboard;
		InputData();

		void pressKey(size_t key);

		void releaseKey(size_t key);

		bool isKeyPressed(size_t key) const;

		

		bool& getKey(size_t key);
		const bool& getKey(size_t key) const;


	private:
		bool windowClosed{ false };
		bool windowFocused{ false };

		std::array<bool, Keyboard::KeyCount> keysStatus;

	};
}