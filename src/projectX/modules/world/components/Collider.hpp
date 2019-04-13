#pragma once

#include "../Component.hpp"

namespace px::Components {
	class RigidBody;
	class Collider : public ComponentBase<RigidBody> {
	public:
		Collider();

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		void setSize(const sf::Vector2f& size);
		void setOffset(const sf::Vector2f& offset);

		bool contains(const Collider& collider) const;

		const sf::Vector2f& getSize() const;
		const sf::Vector2f& getOffset() const;

	private:
		sf::Vector2f offset{ 0.f, 0.f };
		sf::Vector2f size{ 50.f, 50.f };
		sf::RectangleShape d_hitbox{ size };
	};
}