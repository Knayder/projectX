#pragma once

#include "../Component.hpp"
#include <iostream>
namespace px {
	class Test : public ComponentBase<> {
	public:
		float r = 100.f;
		virtual void update(float deltaTime) {
			r += 10.f* deltaTime;
			getParent()->move(40.f*deltaTime, 20.f*deltaTime);
		}

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
			sf::CircleShape shape(r);
			shape.setFillColor(sf::Color::Green);
			target.draw(shape, states);
		}

		virtual void input(const sf::Event& event) override {
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::A)
					std::cout << "A\n";
			}
		}
	};
}