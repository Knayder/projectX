#include "FullDirectoryResourceLoader.hpp"

#ifdef __GNUG__
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif

#include <algorithm>


namespace px {

	FullDirectoryResourceLoader::FullDirectoryResourceLoader(ResourceManager& manager)
		:
		manager(manager)
	{
	}

	void FullDirectoryResourceLoader::loadFromDirectory(const std::string & directoryPath)
	{
		for (const auto& subDirectory : fs::recursive_directory_iterator(directoryPath))
		{
			auto path = subDirectory.path().string();
			std::replace(path.begin(), path.end(), '\\', '/');
			try
			{
				loadResource(path);
			}
			catch (const std::exception&)
			{
			}
		}

	}


	ResType FullDirectoryResourceLoader::getTypeByPath(const std::string & path) const
	{
		const auto extension = getExtension(path);
		if (extension == "jpg" || extension == "png" || extension == "bmp")
			return ResType::Texture;
		if (extension == "ttf" || extension == "ttc")
			return ResType::Font;
		if (extension == "wav" || extension == "mp3" || extension == "aac" || extension == "flac" || extension == "wma")
			return ResType::SoundBuffer;
		return ResType::NotSupportedType;
	}

	std::string FullDirectoryResourceLoader::getExtension(const std::string & file) const
	{
		return file.substr(file.find_last_of(".") + 1);
	}

	void FullDirectoryResourceLoader::loadResource(const std::string & path)
	{
		auto resType = getTypeByPath(path);
		switch (resType)
		{
		case ResType::Texture:
			manager.load<sf::Texture>(path);
			break;
		case ResType::Font:
			manager.load<sf::Font>(path);
			break;
		case ResType::SoundBuffer:
			manager.load<sf::SoundBuffer>(path);
			break;
		case ResType::NotSupportedType:
			break;
		default:
			break;
		}
	}
	FullDirectoryResourceLoader::~FullDirectoryResourceLoader()
	{
	}

}

