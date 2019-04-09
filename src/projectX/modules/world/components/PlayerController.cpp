#include "PlayerController.hpp"
#include <iostream>

namespace px::Components {
	PlayerController::PlayerController() 
	{

	}


	void PlayerController::update(float deltaTime) {
		getComponent<RigidBody>().applyForce(direction*deltaTime*vMax);
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