#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>

#include "../Component.hpp"
#include "../Object.hpp"

namespace px::Components {
	class PlayerController : public Component {
	public:
		PlayerController();

		virtual void update(float deltaTime) override;

		virtual void input(const sf::Event& event) override;

	private:
		bool up{ false };
		bool down{ false };
		bool left{ false };
		bool right{ false };

		sf::Vector2f velocity{ 0.f, 0.f };
		sf::Vector2f direction{ 0.f, 0.f };

		float vMax{ 500.f };
	};

}