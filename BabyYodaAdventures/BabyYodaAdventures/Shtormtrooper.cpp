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

	m_sprite->setOrigin(
		sf::Vector2f(
			m_sprite->getLocalBounds().left + 80,
			m_sprite->getLocalBounds().top + 80
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
	if (!m_playingDeathAnimation)
	{
		updateComponentMovement(frameTime);
		updateComponentHitbox();
	}
	updateComponentAnimation(frameTime);
}

void Shtormtrooper::updateComponentMovement(const float& frameTime)
{
	m_componentMovement->move(m_currVelocity, frameTime);
}

void Shtormtrooper::updateComponentHitbox()
{
	m_componentHitbox->update();
}

void Shtormtrooper::updateComponentAnimation(const float& frameTime)
{
	if (m_playingDeathAnimation)
	{
		if (m_componentAnimation->animationFinished("DEATH"))
			m_dead = true;
		else
			m_componentAnimation->update("DEATH", frameTime);

		return;
	}

	if (m_hp > 0)
	{
		m_componentAnimation->update("WALK", frameTime);

		if (m_hitten)
		{
			if (m_lastHitTime.getElapsedTime().asSeconds() > 0.2)
			{
				m_hitten = false;
				m_sprite->setColor(sf::Color::White);
			}
		}
	}
	else
	{
		m_sprite->setColor(sf::Color::White);
		m_playingDeathAnimation = true;
	}
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
	m_goalEntity(goalEntity),
	m_hitten(false),
	m_playingDeathAnimation(false),
	m_dead(false)
{
	m_hp = 7; // TODO: loading from config
	calculateVelocity(startPos, goalEntity->getPos(), 100.f);

	initTextureSheet(textureSheet);
	initSprite(startPos.x, startPos.y);

	createComponentMovement(m_currVelocity);
	createComponentHitbox(-54.f, -68.f, 110.f, 134.f);
	createComponentAnimation(SCENE_GAME_SHTORMTROOPER_ANIMATIONS_PATH); // TODO: should be done once for all shtormtroopers
}



//-----------------------------------------------
//		Destructors
//

Shtormtrooper::~Shtormtrooper()
= default;



//-----------------------------------------------
//		Accessors
//

//		Getters

bool Shtormtrooper::dead() const
{
	return m_dead;
}

bool Shtormtrooper::playingDeathAnimation() const
{
	return m_playingDeathAnimation;
}



//-----------------------------------------------
//		Update
//

void Shtormtrooper::update(const float& frameTime)
{
	if (!m_playingDeathAnimation)
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



//-----------------------------------------------
//		Else
//

void Shtormtrooper::processHit()
{
	m_hitten = true;
	m_lastHitTime.restart().asMilliseconds();
	m_sprite->setColor(sf::Color(255, 23, 23));
}

