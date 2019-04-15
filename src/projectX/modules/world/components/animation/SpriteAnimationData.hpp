#pragma once
#include "../../../../resourceManager/ResourceManager.hpp"


namespace px::Components::anim {
	class SpriteAnimationData
	{
	private:
		std::vector<sf::IntRect> frames;

		float wholeTime = 0.f;
		const Texture_t texture;
	public:
		SpriteAnimationData(const Texture_t & texture);

		void setFrames(int nFrames);
		void setFrames(int nRowFrames, int nColumnFrames);
		void setFrames(const sf::IntRect& frameRect);
		void setFrames(const sf::IntRect& frameRect, int nFrames);

		void setAnimationTime(float time);
		void setPerFrameTime(float time);

		float getWholeAnimationTime() const;
		float getPerFrameTime() const;

		int getNumberOfFrames() const {
			return (int)frames.size();
		}

		const Texture_t& getTexture() const {
			return texture;
		}

		const auto begin() { return frames.cbegin(); }
		const auto end() { return frames.cend(); }

		const sf::IntRect& getFrame(int index) const { return frames[index]; }
	};

}