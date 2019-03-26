#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <iostream>

#include <SFML/System/NonCopyable.hpp>

#include "ResourceLoader.h"

namespace px {
	template <typename Res>
	class ResourceHolder : public sf::NonCopyable
	{
	public:
		using Resource_t = std::shared_ptr<const Res>;
	private:
		using ResourceContainer_t = std::unordered_map<std::string, Resource_t>;
	private:
		bool isExtentionSet = false;
		std::string folderName;
		std::string extention;

		ResourceContainer_t resources;
		ResourceLoader<Res> loader;

	public:
		ResourceHolder() = default;

		ResourceHolder(const std::string& folder, const std::string& extention)
			:
			folderName("Resources/" + folder + "/"),
			extention("." + extention),
			isExtentionSet{ true },
			ResourceHolder()
		{
		}

	public:

		Resource_t load(const std::string& name)
		{
			if (auto it = resources.find(name); it != resources.end())
			{
				return it->second;
			}

			const auto fullName = getFullFileName(name);
			
			try
			{
				Resource_t loadedRes = loader.loadResource(fullName);

				resources.insert(std::make_pair(name, loadedRes));
				return loadedRes;
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				throw e;
				//return std::make_shared<const Res>(nullptr);
			}
		}

		Resource_t get(const std::string& name) const
		{
			if (const auto it = resources.find(name); it != resources.end())
			{
				return *it;
			}
			else
			{
				throw std::length_error("Couldn't find resource " + name + ".");
			}
		}

		Resource_t acquire(const std::string& name)
		{
			try
			{
				return get(name);
			}
			catch (const std::length_error&)
			{
				return load(name);
			}
		}

		void deleteAditional()
		{
			for (auto it = resources.begin(); it != resources.end(); )
			{
				if (it->second.use_count() == 1)
				{
					it = resources.erase(it);
				}
				else
				{
					++it;
				}
			}
		}

	

	private:
		std::string getFullFileName(const std::string& name) const
		{
			if(isExtentionSet)
				return folderName + name + extention;
			return name;
		}

	};
}