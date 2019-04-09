#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

namespace px {
	class Object;
	class Component;
	class ComponentsManager : public sf::Drawable {
	public:
		using Components_t = std::vector<Component*>;

		ComponentsManager(Object* owner);

		~ComponentsManager();

		void update(float deltaTime);

		void input(const sf::Event& event);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		template<typename T, typename... Args>
		T& addComponent(Args... args) {
			static_assert(std::is_base_of_v<Component, T>, "Given type is not a component");
			if (T* found = ptrGetComponent<T>())
				return *found;
			T* component = new T(args...);
			component->setParent(owner);
			component->grantAccess(owner);
			components.push_back(component);
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

		Components_t components;
		Object* owner;
	private:
	};
}