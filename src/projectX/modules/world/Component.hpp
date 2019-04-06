#pragma once

#include <SFML/Graphics.hpp>

namespace px {
	class Object;

	class Component : public sf::Drawable {
	public:
		Component();
		virtual ~Component();

		void setParent(Object* parent);
		Object* getParent();
		const Object* getParent() const;

		virtual void update(float deltaTime) {}

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {}

		virtual void input(const sf::Event& event) {}
		

	private:
		Object* parent{ nullptr };
	};
}