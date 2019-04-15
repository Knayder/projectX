#pragma once

#include <utility>
#include "ResourceHolder.hpp"

#include<SFML/Graphics/Texture.hpp>
#include<SFML/Graphics/Font.hpp>
#include<SFML/Audio/SoundBuffer.hpp>

namespace px::rm::prv {
	template <typename... Reses>
	using Holders_t = std::tuple< ResourceHolder< Reses >... >;

	using ResourceHolders_t = Holders_t < 
		sf::Texture,
		sf::Font,
		sf::SoundBuffer
	>;

	template <typename Res>
	using Resource_t = std::shared_ptr< const Res >;

	enum ResType {
		Texture = 0,
		Font,
		SoundBuffer,
		NotSupportedType
	};
}

namespace px {
	using Texture_t = rm::prv::Resource_t<sf::Texture>;
	using Font_t = rm::prv::Resource_t<sf::Font>;
	using SoundBuffer_t = rm::prv::Resource_t<sf::SoundBuffer>;
}