#include "ComponentsManager.hpp"

#include "Object.hpp"
#include "Component.hpp"

#include "projectX/utility/TupleForEach.hpp"
#include <iostream>
namespace px {
	ComponentsManager::ComponentsManager(Object* owner) :
		owner{ owner } {

	}

	ComponentsManager::ComponentsManager(ComponentsManager && componentsManager) :
		components{ std::move(componentsManager.components) },
		owner{componentsManager.owner}
	{
		
	}

	ComponentsManager::~ComponentsManager() {
		for (auto& it : components)
			delete it;
	}

	void ComponentsManager::update(float deltaTime) {
		for (auto& component : components)
			component->update(deltaTime);
	}

	void ComponentsManager::input(const sf::Event & event) {
		for (auto& component : components)
			component->input(event);
	}

	void ComponentsManager::draw(sf::RenderTarget & target, sf::RenderStates states) const {
		for (auto& component : components)
			target.draw(*component, states);
	}
	void ComponentsManager::setOwner(Object * newOwner) {
		owner = newOwner;
		for (auto& component : components)
			component->setParent(newOwner);
	}
}
