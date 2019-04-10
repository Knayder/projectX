#pragma once

#include <tuple>
#include <vector>

#include "components/Collider.hpp"

namespace px {

	template<typename... Components>
	class ComponentsTracker {
	public:
		using TrackedComponents_t = std::tuple<std::vector<Components*>...>;



		template<typename T>
		static void checkIfTracked(T* component) {
			if constexpr (tt::tuple_contains_type<std::vector<T*>, TrackedComponents_t>())
				std::get<std::vector<T*>>(trackedComponents).push_back(component);

		}

		static void clearTrackedComponents() {

		}

		template<typename T>
		static std::vector<T*>& getTrackedComponents() {
			static_assert(tt::tuple_contains_type<std::vector<T*>, TrackedComponents_t>(), "That component was not track");
			return std::get<std::vector<T*>>(trackedComponents);
		}
	private:
		inline static TrackedComponents_t trackedComponents{};
	};

	using ComponentsTracker_t = ComponentsTracker<Components::Collider>;
}