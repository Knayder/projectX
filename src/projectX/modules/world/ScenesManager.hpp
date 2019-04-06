#pragma once

#include <map>

#include <SFML/Graphics.hpp>

#include "Scene.hpp"


namespace px {
	class ScenesManager : public sf::Drawable {
	public:
		using Scenes_t = std::map<std::string, Scene>;

		ScenesManager();

		void update(float deltaTime);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		void input(const sf::Event& event);

		Scene& addScene(const std::string& name);

		Scene& getScene(const std::string& name);

		const Scene& getScene(const std::string& name) const;

	private:

		Scenes_t scenes;
	};
}