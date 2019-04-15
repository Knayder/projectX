#include "SpriteAnimationData.hpp"


namespace px::Components::anim {
	SpriteAnimationData::SpriteAnimationData(const Texture_t & texture)
		:
		texture(texture)
	{
	}
	void SpriteAnimationData::setFrames(int nFrames)
	{
		setFrames(nFrames, 1);
	}
	void SpriteAnimationData::setFrames(int nRowFrames, int nColumnFrames)
	{
		frames.clear();
		const auto texSize = texture->getSize();
		const int width = texSize.x / nRowFrames;
		const int height = texSize.y / nColumnFrames;

		for (int y = 0; y < nColumnFrames; ++y)
		{
			for (int x = 0; x < nRowFrames; x++)
			{
				sf::IntRect frame;
				frame.width = width;
				frame.height = height;

				frame.left = x * width;
				frame.top = y * height;

				frames.push_back(frame);
			}
		}
	}
	void SpriteAnimationData::setFrames(const sf::IntRect & frameRect)
	{
		const auto texSize = texture->getSize();
		int nRowFrames = texSize.x / frameRect.width;
		int nColumnFrames = (texSize.y - frameRect.top - frameRect.height) / frameRect.height;
		int nFirstRowFrames = (texSize.x - frameRect.left) / frameRect.width;

		int nFrames = nRowFrames * nColumnFrames + nFirstRowFrames;

		setFrames(frameRect, nFrames);
	}
	void SpriteAnimationData::setFrames(const sf::IntRect & frameRect, int nFrames)
	{
		const auto texSize = texture->getSize();
		int nRowFrames = texSize.x / frameRect.width;
		int nColumnFrames = (texSize.y - frameRect.top) / frameRect.height;

		int nFirstRowFrames = (texSize.x - frameRect.left) / frameRect.width;
		int n = 0;
		for (int x = 0; x < nFirstRowFrames && n < nFrames; x++, ++n)
		{
			auto frame = frameRect;
			frame.left += x * frameRect.width;
			frames.push_back(frame);
		}

		for (int y = 1; y < nColumnFrames; y++)
		{
			for (int x = 0; x < nRowFrames && n < nFrames; x++, ++n)
			{
				sf::IntRect frame = frameRect;
				frame.left = x * frameRect.width;
				frame.top = y * frameRect.height + frameRect.top;
				frames.push_back(frame);
			}
		}
	}

	void SpriteAnimationData::setAnimationTime(float time)
	{
		wholeTime = time;
	}
	void SpriteAnimationData::setPerFrameTime(float time)
	{
		wholeTime = time * float(frames.size());
	}
	float SpriteAnimationData::getWholeAnimationTime() const
	{
		return wholeTime;
	}
	float SpriteAnimationData::getPerFrameTime() const
	{
		return wholeTime / float(frames.size());
	}
}



