#pragma once

#include <memory>
#include <string>
#include <exception>

namespace px {
	template <typename Res>
	struct SingleResourceLoader
	{
		using Resource_t = std::shared_ptr<const Res>;

		Resource_t loadResource(const std::string& name)
		{
			Res res;
			bool loadedProperly = res.loadFromFile(name);
			if (!loadedProperly)
			{
				std::string errorMessage{ "Cannot load \"" + name + "\" file." };
				throw std::runtime_error(errorMessage.c_str());
			}
			return std::make_shared<const Res>(res);
		}

	};
}