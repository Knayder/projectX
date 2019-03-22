#include "Object.hpp"
#include "Scene.hpp"

namespace px {
	Object::Object(Scene* parent) :
		parent{parent} {

	}

	void Object::update(float deltaTime) {
		for (auto& component : components)
			component->update(deltaTime);
	}

	void Object::draw(sf::RenderTarget & target, sf::RenderStates states) const {
		states.transform *= getTransform();
		for (auto& component : components)
			target.draw(*component, states);
	}

	void Object::input(const sf::Event & event) {
		for (auto& component : components)
			component->input(event);
	}

	void Object::setParent(Scene * parent) {
		this->parent = parent;
	}

	Scene* Object::getParent() const {
		return parent;
	}
}