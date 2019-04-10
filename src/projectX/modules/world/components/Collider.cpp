#include "Collider.hpp"

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
	const sf::Vector2f & Collider::getSize() const {
		return size;
	}
	const sf::Vector2f & Collider::getOffset() const {
		return offset;
	}
}
