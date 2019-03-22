#pragma once

#include <SFML/Graphics.hpp>

#include "projectX/utility/Module.hpp"
#include "projectX/modules/renderer/Renderer.hpp"

#include "Scene.hpp"

namespace px {
	class World : public Module<Renderer> {
	public:
		void init();

		void update(float deltaTime);

		void draw();

		void input(const sf::Event& event);
	private:
		sf::RenderTexture* renderTexture{ nullptr };
		Scene scene;
	};
}