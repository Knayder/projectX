#pragma once

#include <SFML/Graphics.hpp>

#include "projectX/utility/Module.hpp"

namespace px {
	class Window : public Module<> {
	public:
		Window() {}
		void init(unsigned int width, unsigned int height, const std::string& title);

		void tempUpdate();

		void clear(sf::Color color = sf::Color::Black);

		void display();

		void draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);

		bool isOpen() const;

		bool pollEvent(sf::Event& event);


		sf::Vector2u getWindowSize() const;


	private:
		sf::RenderWindow window;
	};

}