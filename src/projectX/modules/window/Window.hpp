#pragma once

#include <SFML/Graphics.hpp>

#include "../../utility/Module.hpp"

namespace px {
	class Window : public Module<> {
	public:
		Window() {}
		void init(unsigned int width, unsigned int height, const std::string& title);

		void tempUpdate();

		void clear(sf::Color color = sf::Color::Black);

		void display();

		bool isOpen() const;


	private:
		sf::RenderWindow window;
	};

}