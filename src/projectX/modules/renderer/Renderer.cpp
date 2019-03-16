#include "Renderer.hpp"

#include <exception>

namespace px {
	void Renderer::init() {
		auto windowSize = getModule<Window>().getWindowSize();
		for (auto& layer : layers)
			layer.create(windowSize.x, windowSize.y);
	}
	void Renderer::clear(const sf::Color& color) {
		for (auto& layer : layers)
			layer.clear(color);
	}
	void Renderer::draw(size_t layerID, const sf::Drawable& drawable, const sf::RenderStates& states) {
		getLayer(layerID).draw(drawable, states);
	}

	const sf::RenderTexture & Renderer::getLayer(size_t layerID) const {
		if (layerID >= Layer::COUNT)
			throw std::length_error("Wrong layer id");
		return layers[layerID];
	}

	sf::RenderTexture & Renderer::getLayer(size_t layerID) {
		if (layerID >= Layer::COUNT)
			throw std::length_error("Wrong layer id");
		return layers[layerID];
	}

	void Renderer::display() {
		sf::Sprite sprite;
		auto& window = getModule<Window>();
		for (auto& layer : layers) {
			layer.display();
			sprite.setTexture(layer.getTexture());
			window.draw(sprite);
		}
	}
}