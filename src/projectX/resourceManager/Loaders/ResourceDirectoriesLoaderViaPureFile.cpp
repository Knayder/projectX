#include "ResourceDirectoriesLoaderViaPureFile.hpp"

#include <exception>

namespace px::rm {

	void ResourceDirectoriesLoaderViaPureFile::preload(const std::string & fileName) const
	{
		in.open(fileName);
		if (!in.good())
		{
			std::string errMsg = "ResourceDirectoriesLoaderViaPureFile could not open " + fileName + ".";
			throw std::runtime_error(errMsg.c_str());
		}
		in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		in >> folderName;
	}
	ResourceDirectory ResourceDirectoriesLoaderViaPureFile::getNextDirectory() const
	{
		ResourceDirectory directory;
		in >> directory.fileName;
		directory.fileName = folderName + directory.fileName;
		int type;
		in >> type;
		directory.type = static_cast<rm::prv::ResType>(type);
		if (in.eof())
			empty = true;
		return directory;
	}
	bool ResourceDirectoriesLoaderViaPureFile::isEmpty() const
	{
		return empty;
	}
}
