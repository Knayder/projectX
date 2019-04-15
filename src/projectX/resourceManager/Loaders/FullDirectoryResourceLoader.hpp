#pragma once

#include "../ResourceManager.hpp"
#include "../PrivateUtility/SupportedResourceTypes.hpp"

namespace px::rm {

	class FullDirectoryResourceLoader
	{
		ResourceManager& manager;
		using ResType =  rm::prv::ResType;
	public:
		FullDirectoryResourceLoader(ResourceManager& manager);
		void loadFromDirectory(const std::string& directoryPath);
		~FullDirectoryResourceLoader();
	private:
		void loadResource(const std::string& path);
		ResType getTypeByPath(const std::string& path) const;
		std::string getExtension(const std::string& file) const;
	};
}

