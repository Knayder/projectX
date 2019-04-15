#pragma once
#include "ResourceDirectoriesLoaderBase.hpp"
#include <fstream>

namespace px::rm {
	class ResourceDirectoriesLoaderViaPureFile : public ResourceDirectoriesLoaderBase
	{
	private:
		mutable std::ifstream in;
		mutable bool empty = false;
		mutable std::string folderName;
	public:

		virtual void preload(const std::string& fileName) const override;
		virtual ResourceDirectory getNextDirectory() const override;
		virtual bool isEmpty() const override;
	};

}