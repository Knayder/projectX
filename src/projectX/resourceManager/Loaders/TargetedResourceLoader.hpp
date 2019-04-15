#pragma once

#include "../PrivateUtility/SupportedResourceTypes.hpp"
#include "../ResourceManager.hpp"

#include "ResourceDirectoriesLoaderViaPureFile.hpp"

namespace px::rm {
	class TargetedResourceLoader
	{
	private:
		ResourceManager& manager;
	public:
		TargetedResourceLoader(ResourceManager& manager);
		void load(const std::string& targetingFileName, const ResourceDirectoriesLoaderBase& dirLoader = ResourceDirectoriesLoaderViaPureFile());
	};
}