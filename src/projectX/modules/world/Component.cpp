#include "Component.hpp"

#include "Object.hpp"
#include <iostream>

namespace px {
	Component::Component() {

	}
	Component::~Component() {
	}
	void Component::setParent(Object * parent) {
		this->parent = parent;
	}
	const Object * Component::getParent() const {
		return parent;
	}
	Object * Component::getParent() {
		return parent;
	}
}
