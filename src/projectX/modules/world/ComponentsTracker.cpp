#include "ComponentsTracker.hpp"

#include <iostream>

namespace px {
	template<> 
	void handleTrackedComponents(const std::vector<Components::Collider*>& vec, float) {
		for (auto it = vec.begin(); it != vec.end(); ++it) {
			for (auto it2 = it + 1; it2 != vec.end(); ++it2) {
				Components::Collider& col1 = **it;
				Components::Collider& col2 = **it2;
				if (col1.contains(col2)) {
					Components::RigidBody& rig1 = col1.getComponent<Components::RigidBody>();
					Components::RigidBody& rig2 = col2.getComponent<Components::RigidBody>();
					sf::Vector2f velocity = rig1.velocity + rig2.velocity;
					rig1.velocity = velocity / 2.f;
					rig2.velocity = 1.1f*(velocity / 2.f);
				}
			}
		}
	}
}