#pragma once
#include "../../../../resourceManager/ResourceManager.hpp"


namespace px::Components::anim {
	class AnimationData
	{
	private:
		std::vector<sf::IntRect> frames;

		float wholeTime = 0.f;
	public:
		Texture_t texture;
		AnimationData(const Texture_t & texture);

		AnimationData& operator=(const AnimationData& rhs);

		void setFrames(int nFrames);
		void setFrames(int xFrames, int yFrames);
		void setFrames(sf::IntRect& frameRect);
		void setFrames(sf::IntRect& frameRect, int nFrames);

		void setAnimationTime(float time);
		void setPerFrameTime(float time);

		float getWholeAnimationTime() const;
		float getPerFrameTime() const;

		int size() const {
			return (int)frames.size();
		}

		const auto begin() { return frames.cbegin(); }
		const auto end() { return frames.cend(); }

		const sf::IntRect& getFrame(int index) const { return frames[index]; }
	};

}