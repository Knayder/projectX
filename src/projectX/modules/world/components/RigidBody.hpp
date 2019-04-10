#pragma once

#include "projectX/modules/world/Component.hpp"
#include "Collider.hpp"

namespace px::Components {
	class RigidBody : public ComponentBase<Collider> {
	public:
		RigidBody();

		virtual void update(float deltaTime) override;

		void applyForce(const sf::Vector2f& force);
		void addVelocity(const sf::Vector2f& velocity);
		void setVelocity(const sf::Vector2f& velocity);


		float friction{ 0.05f };
		float mass{ 1.f };
		sf::Vector2f velocity{ 0.f, 0.f };
	private:


	};
}