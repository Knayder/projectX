#pragma once

#include "ResourceManager.hpp"

namespace px {

	class FullDirectoryResourceLoader
	{
		ResourceManager& manager;
	public:
		FullDirectoryResourceLoader(ResourceManager& manager);
		void loadFromDirectory(const std::string& directoryPath);
		~FullDirectoryResourceLoader();
	private:
		enum ResType {
			Texture,
			Font,
			SoundBuffer,
			NotSupportedType
		};
		void loadResource(const std::string& path);
		ResType getTypeByPath(const std::string& path) const;
		std::string getExtension(const std::string& file) const;
	};
}

