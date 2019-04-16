#include "SpriteAnimation.hpp"

namespace px::Components {
	void SpriteAnimation::run()
	{
		if (state == State::WithoutData)
			return;
		state = State::Running;
		reset();
	}
	void SpriteAnimation::stop()
	{
		state = State::Stopped;
		reset();
	}
	void SpriteAnimation::pause()
	{
		state = State::Paused;
	}
	void SpriteAnimation::resume()
	{
		if (state == State::WithoutData)
			return;
		state = State::Running;
	}
	void SpriteAnimation::reset()
	{
		currentTime = 0.f;
		iCurrentFrame = 0;
		isFrameChanged = true;
		mustStopAfterThisFrame = false;
	}
	void SpriteAnimation::update(float dt)
	{
		switch (state)
		{
		case px::Components::SpriteAnimation::WithoutData:
			break;
		case px::Components::SpriteAnimation::Paused:
			break;
		case px::Components::SpriteAnimation::Stopped:
			break;
		case px::Components::SpriteAnimation::Running:
			advance(dt);
			if (isFrameChanged)
				applyToSprite();
			break;
		default:
			break;
		}
	}
	void SpriteAnimation::setData(const anim::SpriteAnimationData & data)
	{
		this->data = &data;
		state = State::Stopped;
	}
	void SpriteAnimation::applyToSprite()
	{
		getComponent<Sprite>().setTexture(data->getTexture(), data->getFrame(iCurrentFrame));
		isFrameChanged = false;
		if (mustStopAfterThisFrame)
		{
			stop();
		}
	}
	void SpriteAnimation::advance(float dt)
	{
		currentTime += dt;
		const int iNextFrame = getNextFrameIndex();
		if (iNextFrame != iCurrentFrame)
		{
			iCurrentFrame = iNextFrame;
			isFrameChanged = true;
			if (!isLooped && iNextFrame == data->getNumberOfFrames() - 1)
			{
				mustStopAfterThisFrame = true;
			}
		}
	}
	int SpriteAnimation::getNextFrameIndex() const
	{
		const float wholeTime = data->getWholeAnimationTime();
		const int nFrames = data->getNumberOfFrames();
		int nextFrameIndex = int( (currentTime / wholeTime) * float(nFrames) );
		if (isLooped)
		{
			return nextFrameIndex % nFrames;
		}
		return std::min(nextFrameIndex, nFrames - 1);
	}
}
