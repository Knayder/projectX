#include "Object.hpp"
#include "Scene.hpp"

namespace px {
	Object::Object(Scene* parent) :
		parent{parent} {

	}

	Object::Object(Object && object):
		parent{std::move(object.parent)},
		componentsManager{std::move(object.componentsManager)}
	{
		componentsManager.setOwner(this);
		setPosition(object.getPosition());
	}

	void Object::update(float deltaTime) {
		componentsManager.update(deltaTime);
	}

	void Object::draw(sf::RenderTarget & target, sf::RenderStates states) const {
		states.transform *= getTransform();
		target.draw(componentsManager, states);
	}

	void Object::input(const sf::Event & event) {
		componentsManager.input(event);
	}

	void Object::setParent(Scene * parent) {
		this->parent = parent;
	}

	Scene* Object::getParent() const {
		return parent;
	}
}