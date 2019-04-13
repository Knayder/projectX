#include "Animation.hpp"

namespace px::Components {

	Animation::Animation()
	{
	}
	void Animation::setTexture(Texture_t texture)
	{
	}
	void Animation::setFrames(int nFrames)
	{
		setFrames(nFrames, 1);
	}
	void Animation::setFrames(int xFrames, int yFrames)
	{
		frames.clear();
		const auto texSize = texture->getSize();
		const int width = texSize.x / xFrames;
		const int height = texSize.y / yFrames;

		for (int y = 0; y < yFrames; ++y)
		{
			for (int x = 0; x < xFrames; x++)
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
	void Animation::setFrames(sf::IntRect & frameRect)
	{
		const auto texSize = texture->getSize();
		int xFrames = texSize.x / frameRect.width;
		int yFrames = (texSize.y - frameRect.top - frameRect.height) / frameRect.height;
		int nFirstRowFrames = (texSize.x - frameRect.left) / frameRect.width;

		int nFrames = xFrames * yFrames + nFirstRowFrames;

		setFrames(frameRect, nFrames);
	}
	void Animation::setFrames(sf::IntRect & frameRect, int nFrames)
	{
		const auto texSize = texture->getSize();
		int xFrames = texSize.x / frameRect.width;
		int yFrames = (texSize.y - frameRect.top) / frameRect.height;

		int nFirstRowFrames = (texSize.x - frameRect.left) / frameRect.width;
		int n = 0;
		for (int x = 0; x < nFirstRowFrames && n < nFrames; x++, ++n)
		{
			auto frame = frameRect;
			frame.left += x * frameRect.width;
			frames.push_back(frame);
		}

		for (int y = 1; y < yFrames; y++)
		{
			for (int x = 0; x < xFrames && n < nFrames; x++, ++n)
			{
				sf::IntRect frame = frameRect;
				frame.left = x * frameRect.width;
				frame.top = y * frameRect.height + frameRect.top;
				frames.push_back(frame);
			}
		}
	}
}
