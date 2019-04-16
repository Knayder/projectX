#pragma once

#include "../Loaders/FullDirectoryResourceLoader.hpp"
#include "../ResourceManager.hpp"

#include "../Loaders/TargetedResourceLoader.hpp"

namespace px::rm::prv {
	class ResourceManagerTests {
	public:
		void runTests()
		{
			auto& manager = ResourceManager::instance();

			//targetLoader.load("Textures/textures.txt");
			manager.load<sf::Texture>("assets/test.png");
			//loader.loadFromDirectory("Textures");
			try
			{
				auto tex = manager.get<sf::Texture>("assets/test.png");
				std::cout << "Loaded\n";

				manager.deleteAditional();
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << '\n';
			}
		}
	};
}