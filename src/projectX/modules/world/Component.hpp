#pragma once

#include <SFML/Graphics.hpp>

#include "projectX/utility/TypeTraits.hpp"
#include "Object.hpp"


namespace px {
	class Component : public sf::Drawable {
	public:
		Component();
		virtual ~Component();

		void setParent(Object* parent);
		Object* getParent();
		const Object* getParent() const;

		virtual void update(float deltaTime) {}

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {}

		virtual void input(const sf::Event& event) {}
		

	private:
		Object* parent{ nullptr };
	};

	template<typename... Deps>
	class ComponentBase : public Component {
	public:
		struct {
			std::tuple<Deps*...> deps;
			void operator()(Object* object) {
				((std::get<Deps*>(deps) = &(object->addComponent<Deps>())), ...);
			}
		} grantAccess;

		template<typename T>
		T& getComponent() {
			static_assert(tt::tuple_contains_type<T, std::tuple<Deps...>>(), "Given component is not dependecy");
			return *std::get<T*>(grantAccess.deps);
		}
	};
}