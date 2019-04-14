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
	void Sprite::setTexture(const Texture_t & texture)
	{
		const auto size = texture->getSize();
		sf::IntRect textureRect{ 0, 0, int(size.x), int(size.y) };
		setTexture(texture, textureRect);
	}
	void Sprite::setTexture(const Texture_t & texture, const sf::IntRect & textureRect)
	{
		if (this->texture != texture)
		{
			this->texture = texture;
			sprite.setTexture(*texture);
		}
		sprite.setTextureRect(textureRect);
	}
}
