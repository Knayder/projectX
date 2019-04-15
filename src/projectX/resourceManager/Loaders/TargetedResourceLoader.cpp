#include "TargetedResourceLoader.hpp"

namespace px::rm {
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
			case prv::ResType::Texture:
				manager.load<sf::Texture>(nextDir.fileName);
				break;
			case prv::ResType::Font:
				manager.load<sf::Font>(nextDir.fileName);
				break;
			case prv::ResType::SoundBuffer:
				manager.load<sf::SoundBuffer>(nextDir.fileName);
				break;
			case prv::ResType::NotSupportedType:
				break;
			default:
				break;
			}
		}
	}
}
