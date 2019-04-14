#include "World.hpp"
#include "components/Sprite.hpp"
#include "components/PlayerController.hpp"
#include "components/RigidBody.hpp"
#include "components/Collider.hpp"
#include "ComponentsTracker.hpp"
#include "components/Animation.hpp"


namespace px {
	void World::init() {
		renderTexture = &getModule<Renderer>().getLayer(Renderer::Layer::Game);
		auto& scene = scenesManager.addScene("test");


		auto& obj = scene.addObject();
		obj.setPosition({ 500.f, 500.f });
		obj.addComponent<Components::Sprite>();
		auto& plr = obj.addComponent<Components::PlayerController>();
		auto& col = plr.getComponent<Components::RigidBody>().getComponent<Components::Collider>().getComponent<Components::RigidBody>().getComponent<Components::Collider>();

		col.setSize({ 100.f, 170.f });
		col.setOffset({ 40.f, 10.f });

		auto& anim = obj.addComponent<Components::Animation>();

		auto tex = ResourceManager::instance().acquire<sf::Texture>("assets/animation_test.png");
		Components::anim::AnimationData animData(tex);
		animData.setFrames(8, 2);
		animData.setPerFrameTime(1.f / 4.f);
		anim.setData(animData);
		anim.isLooped = true;
		anim.run();

		
		auto& obj2 = scene.addObject();
		obj2.addComponent<Components::Sprite>();
		auto& col2 = obj2.addComponent<Components::Collider>();

		col2.setSize({ 100.f, 170.f });
		col2.setOffset({ 40.f, 10.f });

	}

	void World::update(float deltaTime) {
		ComponentsTracker_t::update(deltaTime);
		scenesManager.update(deltaTime);
	}

	void World::draw() {
		renderTexture->draw(scenesManager);
	}

	void World::input(const sf::Event & event) {
		scenesManager.input(event);
	}
}