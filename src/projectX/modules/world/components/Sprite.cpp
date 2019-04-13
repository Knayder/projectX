#include "Sprite.hpp"

#include "projectX/resourceManager/ResourceManager.hpp"
#include <string>

namespace px::Components {
	Sprite::Sprite() {
		auto& resMan = ResourceManager::instance();
		texture = resMan.acquire<sf::Texture>("assets/test.png");
		sprite.setTexture(*texture);
	}

	void Sprite::draw(sf::RenderTarget & target, sf::RenderStates states) const {
		target.draw(sprite, states);
	}
}
