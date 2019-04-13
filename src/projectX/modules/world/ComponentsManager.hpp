#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <tuple>

#include "projectX/utility/TypeTraits.hpp"

#include "Component.hpp"
#include "ComponentsTracker.hpp"

namespace px {

	class Object;

	class ComponentsManager : public sf::Drawable {
	public:
		using Components_t = std::vector<Component*>;

		ComponentsManager(Object* owner);

		ComponentsManager(ComponentsManager&& componentsManager);

		~ComponentsManager();

		void update(float deltaTime);

		void input(const sf::Event& event);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		void setOwner(Object* newOwner);

		template<typename... Deps>
		void grantAccessToComponent(ComponentBase<Deps...>* component) {
			component->grantAccess(addComponent<Deps>()...);
		}

		template<typename T, typename... Args>
		T& addComponent(Args... args) {
			static_assert(std::is_base_of_v<Component, T>, "Given type is not a component");
			if (T* found = ptrGetComponent<T>())
				return *found;
			T* component = new T(args...);
			component->setParent(owner);
			components.push_back(component);
			grantAccessToComponent(component);
			ComponentsTracker_t::checkIfTracked(component);
			return *component;
		}

		template<typename T>
		T& getComponent() {
			for (auto& component : components)
				if (T* searchedComponent = dynamic_cast<T*>(component))
					return *searchedComponent;
			throw std::out_of_range("There is no such a component in a object");
		}

		template<typename T>
		T* ptrGetComponent() {
			for (auto& component : components)
				if (T* searchedComponent = dynamic_cast<T*>(component))
					return searchedComponent;
			return nullptr;
		}



	private:
		Components_t components;
		Object* owner;

	};
}