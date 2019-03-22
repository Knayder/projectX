#include "World.hpp"
#include "components/Test.hpp"


namespace px {
	void World::init() {
		renderTexture = &getModule<Renderer>().getLayer(Renderer::Layer::Game);
		auto& obj = scene.addObject();
		obj.addComponent<Test>();
		obj.move({ 100.f, 100.f });
	}

	void World::update(float deltaTime) {
		scene.update(deltaTime);
	}

	void World::draw() {
		renderTexture->draw(scene);
	}

	void World::input(const sf::Event & event) {
		scene.input(event);
	}
}