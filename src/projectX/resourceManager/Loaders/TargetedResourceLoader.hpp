#pragma once

#include "../PrivateUtility/ResTypes.hpp"
#include "../ResourceManager.hpp"

#include "ResourceDirectoriesLoaderViaPureFile.hpp"

namespace px {
	class TargetedResourceLoader
	{
	private:
		ResourceManager& manager;
	public:
		TargetedResourceLoader(ResourceManager& manager);
		void load(const std::string& targetingFileName, const ResourceDirectoriesLoaderBase& dirLoader = ResourceDirectoriesLoaderViaPureFile());
	};
}