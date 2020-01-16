#include "stdafx.hpp"
#include "MagmaBall.hpp"

#include "Config_Scene_Game.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

void MagmaBall::calculateVelocity(const sf::Vector2f& playerPos, const sf::Vector2f& mousePos, float startVelocity)
{
	float deltaX = mousePos.x - playerPos.x;
	float deltaY = mousePos.y - playerPos.y;

	m_alpha = atan(abs(deltaY) / abs(deltaX));
	m_velocityX = startVelocity * cos(m_alpha);
	if (deltaX < 0)
	{
		m_velocityX *= -1;
	}

	m_velocityY = startVelocity * sin(m_alpha);
	if (deltaY < 0)
	{
		m_velocityY *= -1;
	}
}

void MagmaBall::initSprite(const float& startX, const float& startY)
{
	Entity::initSprite(startX, startY);

	//float angle = m_alpha * 180 / 3.14;
	//float rotation = angle;

	//if (m_velocityX > 0 && m_velocityY < 0)
	//	rotation = 270 + (90 - angle);
	//else if (m_velocityX < 0 && m_velocityY < 0)
	//	rotation = 180 + angle;
	//else if (m_velocityX < 0 && m_velocityY > 0)
	//	rotation = 90 + (90 - angle);
	//m_sprite->setRotation(rotation);
	//m_rotation = rotation;
	m_sprite->setOrigin(
		sf::Vector2f(
			m_sprite->getLocalBounds().left + 25,
			m_sprite->getLocalBounds().top + 50
		)
	); // TODO: loading from config

}



//-----------------------------------------------
//		Update
//

void MagmaBall::updateComponents(const float& frameTime)
{
	updateComponentMovement(frameTime);
 	updateComponentHitbox();
	updateComponentAnimation(frameTime);
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
	calculateVelocity(playerPos, mousePos, 700.f);
	initTextureSheet(textureSheet);
	initSprite(playerPos.x, playerPos.y);

	createComponentMovement(sf::Vector2f(m_velocityX, m_velocityY)); // TODO: loading from config
	createComponentHitbox(15.f, -18.f, 30.f, 30.f); // TODO: loading from config and use scale
	createComponentAnimation(SCENE_GAME_MAGMABALL_ANIMATIONS_PATH);
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
	//m_componentHitbox->render(renderTarget);
}
