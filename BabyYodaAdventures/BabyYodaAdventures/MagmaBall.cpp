#include "stdafx.hpp"
#include "MagmaBall.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

sf::Vector2f MagmaBall::calculateSpeed(const sf::Vector2f& playerPos, const sf::Vector2f& mousePos, float startVelocity)
{
	float deltaX = mousePos.x - playerPos.x;
	float deltaY = mousePos.y - playerPos.y;

	float alpha = atan(abs(deltaY) / abs(deltaX));
	float velocityX = startVelocity * cos(alpha);
	if (deltaX < 0)
	{
		velocityX *= -1;
	}

	float velocityY = startVelocity * sin(alpha);
	if (deltaY < 0)
	{
		velocityY *= -1;
	}

	return sf::Vector2f(velocityX, velocityY);
}



//-----------------------------------------------
//		Update
//

void MagmaBall::updateComponents(const float& frameTime)
{
	updateComponentMovement(frameTime);
//	updateComponentHitbox();
//	updateComponentAnimation(frameTime);
}

void MagmaBall::updateComponentMovement(const float& frameTime)
{
	m_componentMovement->update(frameTime);
}

void MagmaBall::updateComponentHitbox()
{
	m_componentHitbox->update();
}

void MagmaBall::updateComponentAnimation(const float& frameTime)
{
	m_componentAnimation->update("FLY", frameTime);
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

MagmaBall::MagmaBall(sf::Vector2f playerPos, sf::Vector2f mousePos, shared<sf::Texture>& textureSheet)
{
	initTextureSheet(textureSheet);
	initSprite(playerPos.x, playerPos.y);

	createComponentMovement(calculateSpeed(playerPos, mousePos, 300.f)); // TODO: loading from config
	//createComponentHitbox(m_sprite, 30.f, 2.f, 105.f, 142.5f); // TODO: loading from config and use scale
	//createComponentAnimation(SCENE_GAME_BABY_YODA_ANIMATIONS_PATH);
}



//-----------------------------------------------
//		Destructors
//

MagmaBall::~MagmaBall()
= default;



//-----------------------------------------------
//		Update
//

void MagmaBall::update(const float& frameTime)
{
	updateComponents(frameTime);
}



//-----------------------------------------------
//		Render
//

void MagmaBall::render(shared<sf::RenderTarget> renderTarget)
{
	renderTarget->draw(*m_sprite);
}
