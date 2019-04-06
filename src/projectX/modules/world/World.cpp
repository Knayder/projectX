#include "World.hpp"
#include "components/Sprite.hpp"
#include "components/PlayerController.hpp"


namespace px {
	void World::init() {
		renderTexture = &getModule<Renderer>().getLayer(Renderer::Layer::Game);
		auto& obj = scenesManager.addScene("test").addObject();
		obj.addComponent<Components::Sprite>();
		obj.addComponent<Components::PlayerController>();

	}

	void World::update(float deltaTime) {
		scenesManager.update(deltaTime);
	}

	void World::draw() {
		renderTexture->draw(scenesManager);
	}

	void World::input(const sf::Event & event) {
		scenesManager.input(event);
	}
}