#include "ResourceDirectoriesLoaderViaPureFile.hpp"

#include <exception>

namespace px {

	void ResourceDirectoriesLoaderViaPureFile::preload(const std::string & fileName) const
	{
		in.open(fileName);
		if (in.bad())
		{
			std::string errMsg = "ResourceDirectoriesLoaderViaPureFile could not open " + fileName + ".";
			throw std::exception(errMsg.c_str());
		}
		in >> folderName;
	}
	ResourceDirectory ResourceDirectoriesLoaderViaPureFile::getNextDirectory() const
	{
		ResourceDirectory directory;
		in >> directory.fileName;
		directory.fileName = folderName + directory.fileName;
		int type;
		in >> type;
		directory.type = static_cast<ResType>(type);
		if (in.eof())
			empty = true;
		return directory;
	}
	bool ResourceDirectoriesLoaderViaPureFile::isEmpty() const
	{
		return empty;
	}
}
