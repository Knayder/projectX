#pragma once

#include "../Loaders/FullDirectoryResourceLoader.hpp"
#include "../ResourceManager.hpp"

#include "../Loaders/TargetedResourceLoader.hpp"

namespace px {
	class ResourceManagerTests {
	public:
		void runTests()
		{
			auto& manager = ResourceManager::instance();
			FullDirectoryResourceLoader loader(manager);
			TargetedResourceLoader targetLoader(manager);

			targetLoader.load("Textures/textures.txt");

			//loader.loadFromDirectory("Textures");
			try
			{
				auto tex = manager.get<sf::Texture>("Textures/Test1.png");
				manager.get<sf::Texture>("Textures/SubTex/TestSub.png");
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