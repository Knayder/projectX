#include "TargetedResourceLoader.hpp"

namespace px {
	TargetedResourceLoader::TargetedResourceLoader(ResourceManager & manager)
		:
		manager(manager)
	{
	}
	void TargetedResourceLoader::load(const std::string & targetingFileName, const ResourceDirectoriesLoaderBase& dirLoader)
	{
		dirLoader.preload(targetingFileName);
		while (!dirLoader.isEmpty())
		{
			auto nextDir = dirLoader.getNextDirectory();
			switch (nextDir.type)
			{
			case ResType::Texture:
				manager.load<sf::Texture>(nextDir.fileName);
				break;
			case ResType::Font:
				manager.load<sf::Font>(nextDir.fileName);
				break;
			case ResType::SoundBuffer:
				manager.load<sf::SoundBuffer>(nextDir.fileName);
				break;
			case ResType::NotSupportedType:
				break;
			default:
				break;
			}
		}
	}
}
