#include <vector>


#include "../Component.hpp"
#include "../Object.hpp"
#include "Sprite.hpp"

#include "animation/AnimationData.hpp"

namespace px::Components {
	class Animation : public ComponentBase<Sprite>
	{
	private:
		int iCurrentFrame = 0;
		float currentTime = 0.f;
		bool isFrameChanged = false;
		bool mustStopAfterThisFrame = false;
		const anim::AnimationData* data = nullptr;
		bool isLooped = false;
		
		enum State {
			WithoutData,
			Paused,
			Stopped,
			Running
		} state = State::WithoutData;

	public:
		void makeLooped() { isLooped = true; }
		void makeNotLooped() { isLooped = false; }
		bool isAnimationLooped() const { return isLooped; }

		Animation() = default;

		void run();
		void stop();
		void resume();
		void pause();
		void reset();

		void update(float dt) override;

		void setData(const anim::AnimationData& data);
		
	private:

		void applyToSprite();
		void advance(float dt);
		int getNextFrameIndex() const;
	};
}