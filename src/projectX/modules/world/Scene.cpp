#include "Scene.hpp"


namespace px {
	Scene::Scene() {

	}

	void Scene::update(float deltaTime) {
		for (auto& object : objects)
			object.update(deltaTime);
	}

	void Scene::draw(sf::RenderTarget & target, sf::RenderStates states) const {
		for (auto& object : objects)
			target.draw(object);
	}

	void Scene::input(const sf::Event & event) {
		for (auto& object : objects)
			object.input(event);
	}

	Object& Scene::addObject() {
		return objects.emplace_back(this);
	}

	void Scene::setParent(ScenesManager * parent) {
		this->parent = parent;
	}

	ScenesManager * Scene::getParent() const {
		return parent;
	}
}
