#include "PlayerController.hpp"
#include <iostream>

namespace px::Components {
	PlayerController::PlayerController() {

	}


	void PlayerController::update(float deltaTime) {
		/*sf::Vector2f delta = (direction * vMax) - velocity;
		float c = std::sqrt(delta.x*delta.x + delta.y*delta.y);
		//std::cout << direction.x << std::endl;;
		if(c != 0.f)
			velocity += deltaTime * (delta / (c*0.05f));*/
		float c = std::sqrt(direction.x*direction.x + direction.y*direction.y);
		if (c != 0.f)
			direction /= c;


		getParent()->move(direction*deltaTime*vMax);
	}


	void PlayerController::input(const sf::Event & event) {
		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
				case sf::Keyboard::W:
				direction.y = -1.f;
				break;

				case sf::Keyboard::S:
				direction.y = 1.f;
				break;

				case sf::Keyboard::A:
				direction.x = -1.f;
				break;

				case sf::Keyboard::D:
				direction.x = 1.f;
				break;

			}
		}

		if (event.type == sf::Event::KeyReleased) {
			switch (event.key.code) {
				case sf::Keyboard::W:
				direction.y = 0.f;
				break;

				case sf::Keyboard::S:
				direction.y = 0.f;
				break;

				case sf::Keyboard::A:
				direction.x = 0.f;
				break;

				case sf::Keyboard::D:
				direction.x = 0.f;
				break;

			}
		}
	}
}