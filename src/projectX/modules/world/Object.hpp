#pragma once

#include <vector>
#include <memory>
#include <type_traits>


#include <SFML/Graphics.hpp>

#include "ComponentsManager.hpp"

namespace px {

	class Scene;

	class Object : public sf::Transformable, public sf::Drawable {
	public:
		Object() = delete;

		Object(Scene* parent);

		void update(float deltaTime);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		void input(const sf::Event& event);

		template<typename T, typename... Args>
		T& addComponent(Args... args)	{
			return componentsManager.addComponent<T, Args...>(args...);
		}

		template<typename T>
		T& getComponent() {
			return componentsManager.getComponent<T>();
		}

		void setParent(Scene* parent);
		Scene* getParent() const;
	private:
		ComponentsManager componentsManager{ this };
		Scene* parent{ nullptr };
	};
}