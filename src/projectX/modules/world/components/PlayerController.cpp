#include "PlayerController.hpp"
#include <iostream>

#include "projectX/resourceManager/ResourceManager.hpp"

namespace px::Components {
	PlayerController::PlayerController() 
	{
		const int nFramesPerDirection = 3;
		prepareDirectionAnimations("assets/monk_sprite.png", nFramesPerDirection);
	}


	void PlayerController::update(float deltaTime) {
		const auto force = static_cast<sf::Vector2f>(direction) * deltaTime * vMax;
		getComponent<RigidBody>().applyForce(force);

		getComponent<Sprite>().setScale(3.f);

		updateDirectionAnimation();
		if (iFaceDirChanged)
		{
			auto& animation = getComponent<SpriteAnimation>();
			animation.setData(faceDirectionAnims[iFaceDirection]);
			animation.run();
			animation.makeLooped();
			iFaceDirChanged = false;
		}
	}


	void PlayerController::input(const sf::Event & event) {
		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
				case sf::Keyboard::W:
				direction.y = -1;
				break;

				case sf::Keyboard::S:
				direction.y = 1;
				break;

				case sf::Keyboard::A:
				direction.x = -1;
				break;

				case sf::Keyboard::D:
				direction.x = 1;
				break;

			}
		}

		if (event.type == sf::Event::KeyReleased) {
			switch (event.key.code) {
				case sf::Keyboard::W:
				direction.y = 0;
				break;

				case sf::Keyboard::S:
				direction.y = 0;
				break;

				case sf::Keyboard::A:
				direction.x = 0;
				break;

				case sf::Keyboard::D:
				direction.x = 0;
				break;

			}
		}
	}
	void PlayerController::prepareDirectionAnimations(const std::string & fileName, int nFramesPerDirection)
	{
		auto& rm = ResourceManager::instance();
		auto tex = rm.acquire<sf::Texture>(fileName);
		const auto size = tex->getSize();
		const int frameHeight = size.y / nFaceDirections;
		sf::IntRect frameRect{ 0, 0, int(size.x) / nFramesPerDirection, frameHeight };
		faceDirectionAnims.clear();
		faceDirectionAnims.reserve(2 * Direction::Count);

		for (int i = 0; i < nFaceDirections; i++)
		{
			faceDirectionAnims.push_back(anim::SpriteAnimationData(tex));
			auto& animData = faceDirectionAnims.back();
			animData.setFrames(frameRect, nFramesPerDirection);
			animData.setPerFrameTime(1.f / 8.f);
			frameRect.top += frameHeight;
		}
		frameRect.top = 0;
		for (int i = 0; i < nFaceDirections; i++)
		{
			faceDirectionAnims.push_back(anim::SpriteAnimationData(tex));
			auto& animData = faceDirectionAnims.back();
			animData.setFrames(frameRect, 1);
			animData.setPerFrameTime(1.f / 8.f);
			frameRect.top += frameHeight;
		}
	}
	void PlayerController::updateDirectionAnimation()
	{
		auto oldFaceDirection = iFaceDirection;
		if (!isMoving)
		{
			iFaceDirection = Direction(int(iFaceDirection) - nFaceDirections);
		}
		isMoving = true;
		if (direction.x != 0)
		{
			if (direction.x == 1) {
				iFaceDirection = Direction::RigthWalk;
			}
			else
			{
				iFaceDirection = Direction::LeftWalk;
			}
		}
		else if(direction.y != 0)
		{
			if (direction.y == 1)
			{
				iFaceDirection = Direction::DownWalk;
			}
			else
			{
				iFaceDirection = Direction::UpWalk;
			}
		}
		else
		{
			isMoving = false;
		}

		if (!isMoving)
		{
			iFaceDirection = Direction(int(iFaceDirection) + int(nFaceDirections));
		}

		if (iFaceDirection != oldFaceDirection)
		{
			iFaceDirChanged = true;
		}
	}
}