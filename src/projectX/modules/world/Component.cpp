#include "Component.hpp"

#include "Object.hpp"

namespace px {
	Component::Component() {

	}
	Component::~Component() {

	}
	void Component::setParent(Object * parent) {
		this->parent = parent;
	}
	Object * Component::getParent() const {
		return parent;
	}
}
