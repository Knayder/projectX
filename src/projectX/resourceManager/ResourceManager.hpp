#pragma once

#include <utility>
#include "projectX/utility/TypeTraits.hpp"
#include "projectX/utility/TupleForEach.hpp"

#include<SFML/Graphics/Texture.hpp>
#include<SFML/Graphics/Font.hpp>
#include<SFML/Audio/SoundBuffer.hpp>
#include <SFML/System/NonCopyable.hpp>


#include "ResourceHolder.h"

namespace px {
	class ResourceManager : public sf::NonCopyable
	{
		template <typename... Reses>
		using Holders_t = std::tuple< ResourceHolder< Reses >... >;
		using ResourceHolders_t = Holders_t< sf::Texture, sf::Font, sf::SoundBuffer >;
	public:
		template <typename Res>
		using Resource_t = std::shared_ptr< const Res >;
	private:
		ResourceHolders_t holders;

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
		ResourceHolder<Res>& getHolder()
		{
			static_assert(tt::tuple_contains_type< ResourceHolder<Res>, ResourceHolders_t >(),
				"Resource Manager doesn't support this type of resource");
			return std::get<ResourceHolder<Res>>(holders);
		}
		template <typename Res>
		const ResourceHolder<Res>& getHolder() const
		{
			static_assert(tt::tuple_contains_type< ResourceHolder<Res>, ResourceHolders_t >(),
				"Resource Manager doesn't support this type of resource");
			return std::get<ResourceHolder<Res>>(holders);
		}
	};
}