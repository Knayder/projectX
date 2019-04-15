#pragma once

#include <utility>
#include "projectX/utility/TypeTraits.hpp"
#include "projectX/utility/TupleForEach.hpp"

#include <SFML/System/NonCopyable.hpp>

#include "PrivateUtility/ResourceHolder.hpp"
#include "PrivateUtility/SupportedResourceTypes.hpp"

namespace px {
	class ResourceManager : public sf::NonCopyable
	{
	public:
		template<typename Res>
		using Resource_t = rm::prv::Resource_t<Res>;
		
	private:
		rm::prv::ResourceHolders_t holders;

		 ResourceManager() = default;

	public:
		static ResourceManager& instance()
		{
			static ResourceManager resManager;
			return resManager;
		}

		template <typename Res>
		Resource_t<Res> get(const std::string& name) const
		{
			const auto& holder = getHolder<Res>();
			return holder.get(name);
		}
		template <typename Res>
		Resource_t<Res> load(const std::string& name)
		{
			auto& holder = getHolder<Res>();
			return holder.load(name);
		}
		template <typename Res>
		Resource_t<Res> acquire(const std::string& name)
		{
			auto& holder = getHolder<Res>();
			return holder.acquire(name);
		}

		void deleteAditional()
		{
			forEach(holders, [](auto& holder) {
				holder.deleteAditional();
			});
		}

	private:
		template <typename Res>
		rm::prv::ResourceHolder<Res>& getHolder()
		{
			using namespace rm::prv;
			static_assert(tt::tuple_contains_type< ResourceHolder<Res>, ResourceHolders_t >(),
				"Resource Manager doesn't support this type of resource");
			return std::get<ResourceHolder<Res>>(holders);
		}
		template <typename Res>
		const rm::prv::ResourceHolder<Res>& getHolder() const
		{
			using namespace rm::prv;
			static_assert(tt::tuple_contains_type< ResourceHolder<Res>, ResourceHolders_t >(),
				"Resource Manager doesn't support this type of resource");
			return std::get<ResourceHolder<Res>>(holders);
		}
	};

	
}