#pragma once

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
	private:
		sf::Sprite sprite;
	};
}