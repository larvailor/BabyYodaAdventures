#include "stdafx.hpp"
#include "Shtormtrooper.hpp"

#include "Config_Scene_Game.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

void Shtormtrooper::initSprite(const float& startX, const float& startY)
{
	Entity::initSprite(startX, startY);

	m_sprite->setScale(0.5f, 0.5f);

	m_sprite->setOrigin(
		sf::Vector2f(
			m_sprite->getLocalBounds().left + 130,
			m_sprite->getLocalBounds().top + 129
		)
	); // TODO: loading from config
}

void Shtormtrooper::calculateVelocity(const sf::Vector2f& currPos, const sf::Vector2f& goalPos, float maxVelocity)
{
	float deltaX = goalPos.x - currPos.x;
	float deltaY = goalPos.y - currPos.y;

	float alpha = atan(abs(deltaY) / abs(deltaX));
	m_currVelocity.x = maxVelocity * cos(alpha);
	if (deltaX < 0)
	{
		m_currVelocity.x *= -1;
	}

	m_currVelocity.y = maxVelocity * sin(alpha);
	if (deltaY < 0)
	{
		m_currVelocity.y *= -1;
	}
}



//-----------------------------------------------
//		Update
//

void Shtormtrooper::updateComponents(const float& frameTime)
{
	updateComponentMovement(frameTime);
	updateComponentHitbox();
}

void Shtormtrooper::updateComponentMovement(const float& frameTime)
{
	m_componentMovement->move(m_currVelocity, frameTime);
}

void Shtormtrooper::updateComponentHitbox()
{
	m_componentHitbox->update();
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Shtormtrooper::Shtormtrooper(sf::Vector2f startPos, shared<sf::Texture>& textureSheet, shared<Entity>& goalEntity) :
	m_goalEntity(goalEntity)
{
	m_hp = 10; // TODO: loading from config
	calculateVelocity(startPos, goalEntity->getPos(), 100.f);

	initTextureSheet(textureSheet);
	initSprite(startPos.x, startPos.y);

	createComponentMovement(m_currVelocity);
	createComponentHitbox(-50.f, -60.f, 100.f, 125.f);
}



//-----------------------------------------------
//		Destructors
//

Shtormtrooper::~Shtormtrooper()
= default;



//-----------------------------------------------
//		Update
//

void Shtormtrooper::update(const float& frameTime)
{
	calculateVelocity(m_sprite->getPosition(), m_goalEntity->getPos(), 100.f);
	updateComponents(frameTime);
}



//-----------------------------------------------
//		Render
//

void Shtormtrooper::render(shared<sf::RenderTarget> renderTarget)
{
	renderTarget->draw(*m_sprite);
	// m_componentHitbox->render(renderTarget);
}

