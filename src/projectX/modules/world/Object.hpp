#pragma once

#include <vector>
#include <memory>
#include <type_traits>

#include <SFML/Graphics.hpp>

#include "Component.hpp"

namespace px {

	class Scene;

	class Object : public sf::Transformable, public sf::Drawable {
	public:
		using Components_t = std::vector<std::unique_ptr<Component>>;

		Object() = delete;

		Object(Scene* parent);

		void update(float deltaTime);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		void input(const sf::Event& event);

		template<typename T, typename... Args>
		void addComponent(Args... args)	{
			static_assert(std::is_base_of_v<Component, T>, "Given type is not a component");
			components.emplace_back(new T(args...))->setParent(this);
		}

		template<typename T>
		T& getComponent() {
			for (auto& component : components)
				if (T* gettedComponent = dynamic_cast<T*>(component.get()))
					return *gettedComponent;
			throw std::out_of_range("There is no such a component in a object");
		}

		void setParent(Scene* parent);
		Scene* getParent() const;
	private:
		Components_t components;
		Scene* parent{ nullptr };
	};
}