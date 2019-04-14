#include "Animation.hpp"

namespace px::Components {
	void Animation::run()
	{
		state = State::Running;
		reset();
	}
	void Animation::stop()
	{
		state = State::Stopped;
		reset();
	}
	void Animation::pause()
	{
		state = State::Paused;
	}
	void Animation::resume()
	{
		state = State::Running;
	}
	void Animation::reset()
	{
		currentTime = 0.f;
		iCurrentFrame = 0;
		isFrameChanged = true;
	}
	void Animation::update(float dt)
	{
		switch (state)
		{
		case px::Components::Animation::WithoutData:
			break;
		case px::Components::Animation::Paused:
			break;
		case px::Components::Animation::Stopped:
			break;
		case px::Components::Animation::Running:
			advance(dt);
			if (isFrameChanged)
				applyToSprite();
			break;
		default:
			break;
		}
	}
	void Animation::setData(const anim::AnimationData & data)
	{
		this->data = data;
		state = State::Stopped;
	}
	void Animation::applyToSprite()
	{
		getComponent<Sprite>().setTexture(data.texture, data.getFrame(iCurrentFrame));
		isFrameChanged = false;
	}
	void Animation::advance(float dt)
	{
		currentTime += dt;
		const int iNextFrame = getNextFrameIndex();
		if (!isLooped && iNextFrame >= data.size())
		{
			stop();
		}
		else if (iNextFrame != iCurrentFrame)
		{
			iCurrentFrame = iNextFrame;
			isFrameChanged = true;
		}
	}
	int Animation::getNextFrameIndex() const
	{
		const float wholeTime = data.getWholeAnimationTime();
		const int nFrames = data.size();
		int nextFrameIndex = int( (currentTime / wholeTime) * float(nFrames) );
		if (isLooped)
		{
			return nextFrameIndex % nFrames;
		}
		return nextFrameIndex;
	}
}
