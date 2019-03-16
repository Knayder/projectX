#include "Window.hpp"

namespace px {
	void Window::init(unsigned int width, unsigned int height, const std::string& title) {
		//@TODO: Disable window's size changing
		window.create(sf::VideoMode(width, height), title);
		//window.setFramerateLimit(60);
	}

	void Window::input(const sf::Event& event) {
		if (event.type == sf::Event::Closed)
			window.close();
	}

	void Window::clear(sf::Color color) {
		window.clear(color);
	}

	void Window::display() {
		window.display();
	}

	void Window::draw(const sf::Drawable& drawable, const sf::RenderStates& states) {
		window.draw(drawable, states);
	}

	bool Window::isOpen() const {
		return window.isOpen();
	}

	bool Window::pollEvent(sf::Event & event) {
		return window.pollEvent(event);
	}

	sf::Vector2u Window::getWindowSize() const {
		return window.getSize();
	}

}