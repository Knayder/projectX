#pragma once

#include <SFML/Graphics.hpp>
#include <array>

#include "projectX/utility/Module.hpp"
#include "projectX/modules/window/Window.hpp"

namespace px {
	class Renderer : public Module<Window> {
	public:
		enum Layer : size_t {
			Background = 0,
			Game = 1,
			Effects = 2,
			GUI = 3,
			Foreground = 4,
			COUNT = 5
		};

		using Layers_t = std::array<sf::RenderTexture, Layer::COUNT>;

		Renderer() {}
		void init();

		void clear(const sf::Color& color = sf::Color::Transparent);

		void draw(size_t layerID, const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);

		const sf::RenderTexture& getLayer(size_t layerID) const;

		sf::RenderTexture& getLayer(size_t layerID);

		void display();
		
	private:
		Layers_t layers;


	};
}