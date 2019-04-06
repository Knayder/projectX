#include "Sprite.hpp"

#include "projectX/resourceManager/ResourceManager.hpp"
#include <string>

namespace px::Components {
	Sprite::Sprite() {
		sprite.setTexture(
			*ResourceManager::instance().acquire<sf::Texture>("assets/test.png")
		);
	}

	void Sprite::draw(sf::RenderTarget & target, sf::RenderStates states) const {
		target.draw(sprite, states);
	}
}
