#include "RigidBody.hpp"

#include "projectX/modules/world/Object.hpp"
#include <iostream>
namespace px::Components {
	RigidBody::RigidBody() {

	}

	void RigidBody::update(float deltaTime) {
		velocity -= (velocity * friction) / mass;
		if (std::abs(velocity.x) + std::abs(velocity.y) <= 0.05f)
			velocity = { 0.f, 0.f };

		getParent()->move(velocity * deltaTime);
	}

	void RigidBody::applyForce(const sf::Vector2f & force) {
		this->velocity += force / mass;
	}

	void RigidBody::addVelocity(const sf::Vector2f & velocity) {
		this->velocity += velocity;
	}

	void RigidBody::setVelocity(const sf::Vector2f & velocity) {
		this->velocity = velocity;
	}

}