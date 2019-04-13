#pragma once

#include <tuple>
#include <vector>

#include "components/Collider.hpp"
#include "components/RigidBody.hpp"

#include "projectX/utility/TupleForEach.hpp"

namespace px {
	template<typename...>
	class ComponentsTracker;

	using ComponentsTracker_t = ComponentsTracker<Components::RigidBody, Components::Collider>;

	template<typename T>
	void handleTrackedComponents(const std::vector<T*>& vec, float deltaTime) {

	}

	template<>
	void handleTrackedComponents(const std::vector<Components::Collider*>& vec, float);

	


	template<typename... Components>
	class ComponentsTracker {
	public:
		using TrackedComponents_t = std::tuple<std::vector<Components*>...>;

		static void update(float deltaTime) {
			forEach(trackedComponents, [deltaTime](const auto& list) {
				handleTrackedComponents(list, deltaTime);
			});
		}

		template<typename T>
		static void checkIfTracked(T* component) {
			if constexpr (tt::tuple_contains_type<std::vector<T*>, TrackedComponents_t>())
				std::get<std::vector<T*>>(trackedComponents).push_back(component);

		}

		static void clearTrackedComponents() {
			forEach(trackedComponents, [](auto& list) {
				list.clear();
			});
		}

		template<typename T>
		static std::vector<T*>& getTrackedComponents() {
			static_assert(tt::tuple_contains_type<std::vector<T*>, TrackedComponents_t>(), "That component was not track");
			return std::get<std::vector<T*>>(trackedComponents);
		}
	private:

		inline static TrackedComponents_t trackedComponents{};
	};
}