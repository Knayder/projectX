#include "World.hpp"
#include "components/Sprite.hpp"
#include "components/PlayerController.hpp"
#include "components/RigidBody.hpp"
#include "components/Collider.hpp"
#include "ComponentsTracker.hpp"


namespace px {
	void World::init() {
		renderTexture = &getModule<Renderer>().getLayer(Renderer::Layer::Game);
		auto& obj = scenesManager.addScene("test").addObject();
		obj.addComponent<Components::Sprite>();
		auto& plr = obj.addComponent<Components::PlayerController>();
		auto& colcon = ComponentsTracker_t::getTrackedComponents<Components::Collider>();
		auto& col = *(colcon[0]);

		col.setSize({ 100.f, 170.f });
		col.setOffset({ 40.f, 10.f });

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