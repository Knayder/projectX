#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>

#include "../Component.hpp"
#include "../Object.hpp"

#include "projectX/utility/animation/SpriteAnimationData.hpp"
#include "SpriteAnimation.hpp"
#include "Sprite.hpp"
#include "RigidBody.hpp"

namespace px::Components {
	class PlayerController : public ComponentBase<RigidBody, Sprite, SpriteAnimation> {
	public:
		PlayerController();

		virtual void update(float deltaTime) override;

		virtual void input(const sf::Event& event) override;

	private:
		enum Direction {
			DownWalk, UpWalk, RigthWalk, LeftWalk,
			DownStand, UpStand, RigthStand, LeftStand,
			Count
		};
		static constexpr int nFaceDirections = 4;
		Direction iFaceDirection = Direction::DownStand;
		std::vector<anim::SpriteAnimationData> faceDirectionAnims;
		bool isMoving = false;
		bool iFaceDirChanged = true;

		void prepareDirectionAnimations(const std::string& fileName, int nFramesPerDirection);
		void updateDirectionAnimation();

		sf::Vector2f velocity{ 0.f, 0.f };
		sf::Vector2i direction{ 0, 0 };

		float vMax{ 5000.f };

		//RigidBody& rigidBody;
	};

}