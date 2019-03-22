#pragma once 

#include <SFML/Graphics.hpp>

#include "Object.hpp"


namespace px {
	class ScenesManager;

	class Scene : public sf::Drawable {
	public:
		using Objects_t = std::vector<Object>;

		Scene();

		void update(float deltaTime);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		void input(const sf::Event& event);

		Object& addObject();

		void setParent(ScenesManager* parent);
		ScenesManager* getParent() const;


	private:
		Objects_t objects;
		ScenesManager* parent;
	};
}