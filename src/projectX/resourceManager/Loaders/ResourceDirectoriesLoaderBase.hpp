#pragma once
#include <string>
#include "../PrivateUtility/SupportedResourceTypes.hpp"

namespace px::rm {
	struct ResourceDirectory {
		std::string fileName;
		prv::ResType type;
	};
	class ResourceDirectoriesLoaderBase
	{
	public:
		ResourceDirectoriesLoaderBase() {}
		virtual ~ResourceDirectoriesLoaderBase() {}


		virtual void preload(const std::string& fileName) const = 0;
		virtual ResourceDirectory getNextDirectory() const = 0;
		virtual bool isEmpty() const = 0;

	private:

	};
}