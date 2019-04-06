#include "ScenesManager.hpp"


namespace px {
	ScenesManager::ScenesManager() {
	}

	void ScenesManager::update(float deltaTime) {
		for (auto& scene : scenes)
			scene.second.update(deltaTime);
	}

	void ScenesManager::draw(sf::RenderTarget & target, sf::RenderStates states) const {
		for (auto& scene : scenes)
			target.draw(scene.second, states);
	}

	void ScenesManager::input(const sf::Event & event) {
		for (auto& scene : scenes)
			scene.second.input(event);
	}

	Scene & ScenesManager::addScene(const std::string & name) {
		return scenes.emplace(name, Scene{}).first->second;
	}

	Scene & ScenesManager::getScene(const std::string & name) {
		if (auto it = scenes.find(name); it != scenes.end())
			return it->second;
		else
			throw std::out_of_range("There is no scene with given name");
	}

	const Scene & ScenesManager::getScene(const std::string & name) const {
		if (auto it = scenes.find(name); it != scenes.end())
			return it->second;
		else
			throw std::out_of_range("There is no scene with given name");
	}

}
