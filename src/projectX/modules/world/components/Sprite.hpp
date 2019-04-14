#pragma once

#include "../../../resourceManager/ResourceManager.hpp"

#include "../Component.hpp"
#include "../Object.hpp"
#include <iostream>

namespace px::Components {
	class Sprite : public ComponentBase<> {
	public:
		Sprite();

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		void update(float deltaTime) override {
		}

		void setTexture(const Texture_t& texture);
		void setTexture(const Texture_t& texture, const sf::IntRect& textureRect);
	private:
		sf::Sprite sprite;
		Texture_t texture;
	};
}