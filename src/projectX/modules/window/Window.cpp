#include "Window.hpp"

namespace px {
	void Window::init(unsigned int width, unsigned int height, const std::string& title) {
		window.create(sf::VideoMode(width, height), title);
	}

	void Window::tempUpdate() {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	void Window::clear(sf::Color color) {
		window.clear(color);
	}

	void Window::display() {
		window.display();
	}

	bool Window::isOpen() const
	{
		return window.isOpen();
	}

}