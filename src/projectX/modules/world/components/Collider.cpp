#include "Collider.hpp"
#include "projectX/modules/world/Object.hpp"

namespace px::Components {
	Collider::Collider() {
		d_hitbox.setFillColor(sf::Color{ 255, 0, 255, 128 });
	}

	void Collider::draw(sf::RenderTarget & target, sf::RenderStates states) const {
		target.draw(d_hitbox, states);
	}

	void Collider::setSize(const sf::Vector2f & size) {
		this->size = size;
		d_hitbox.setSize(size);
	}
	void Collider::setOffset(const sf::Vector2f & offset) {
		this->offset = offset;
		d_hitbox.setPosition(offset);
	}
	bool Collider::contains(const Collider & collider) const {
		sf::Vector2f pos = getParent()->getPosition() + offset;
		sf::Vector2f colPos = collider.getParent()->getPosition() + collider.offset;

		if (
			pos.x + size.x >= colPos.x &&
			pos.x <= colPos.x + collider.size.x &&
			pos.y + size.y >= colPos.y &&
			pos.y <= colPos.y + collider.size.y
			) {
			return true;
		}
		return false;
	}
	const sf::Vector2f & Collider::getSize() const {
		return size;
	}
	const sf::Vector2f & Collider::getOffset() const {
		return offset;
	}
}
