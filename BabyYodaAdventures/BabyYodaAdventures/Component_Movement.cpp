#include "stdafx.hpp"
#include "Component_Movement.hpp"

/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Component_Movement::Component_Movement(float maxVelocity, float reachMaxVelocityTime, float reachZeroVelocityTime, shared<sf::Sprite>& sprite) :
	m_maxVelocity(maxVelocity),
	m_sprite(sprite),
	m_movedManuallyX(false),
	m_movedManuallyY(false),
	m_currDirectionX(DirectionX::NONE),
	m_currDirectionY(DirectionY::NONE)
{
	m_acceleration = m_maxVelocity / reachMaxVelocityTime;
	m_deceleration = m_maxVelocity / reachZeroVelocityTime;
}

Component_Movement::Component_Movement(sf::Vector2f startVelocity, shared<sf::Sprite>& sprite) :
	m_currVelocity(startVelocity),
	m_sprite(sprite),
	m_maxVelocity(0.f),
	m_movedManuallyX(false),
	m_movedManuallyY(false),
	m_currDirectionX(DirectionX::NONE),
	m_currDirectionY(DirectionY::NONE),
	m_acceleration(0.f),
	m_deceleration(0.f)
{

}



//-----------------------------------------------
//		Destructors
//

Component_Movement::~Component_Movement()
= default;



//-----------------------------------------------
//		Accesors
//

	// Getters

float Component_Movement::getMaxVelocity() const
{
	return m_maxVelocity;
}

sf::Vector2f Component_Movement::getVelocity() const
{
	return m_currVelocity;
}

DirectionX Component_Movement::getCurrDirectionX() const
{
	return m_currDirectionX;
}

DirectionY Component_Movement::getCurrDirectionY() const
{
	return m_currDirectionY;
}



//-----------------------------------------------
//		Update
//

void Component_Movement::update(const float& frameTime)
{
	// Deceleration
	if (!m_movedManuallyX && m_currVelocity.x != 0.f)
	{
		if (m_currVelocity.x < 0)
		{
			m_currVelocity.x += m_deceleration * frameTime;
			if (m_currVelocity.x > 0)
			{
				m_currVelocity.x = 0.f;
				m_currDirectionX = DirectionX::NONE;
			}
		}
		else
		{
			m_currVelocity.x -= m_deceleration * frameTime;
			if (m_currVelocity.x < 0)
			{
				m_currVelocity.x = 0.f;
				m_currDirectionX = DirectionX::NONE;
			}
		}
	}

	if (!m_movedManuallyY && m_currVelocity.y != 0.f)
	{
		if (m_currVelocity.y < 0)
		{
			m_currVelocity.y += m_deceleration * frameTime;
			if (m_currVelocity.y > 0)
			{
				m_currVelocity.y = 0.f;
				m_currDirectionY = DirectionY::NONE;
			}
		}
		else
		{
			m_currVelocity.y -= m_deceleration * frameTime;
			if (m_currVelocity.y < 0)
			{
				m_currVelocity.y = 0.f;
				m_currDirectionY = DirectionY::NONE;
			}
		}
	}

	m_sprite->move(m_currVelocity * frameTime);

	m_movedManuallyX = false;
	m_movedManuallyY = false;
}



//-----------------------------------------------
//		Input handling
//

void Component_Movement::move(const DirectionX& dirX, const DirectionY& dirY, const float& frameTime)
{
	// Acceleration
	switch (dirX)
	{
	case DirectionX::LEFT:
		m_movedManuallyX = true;
		m_currDirectionX = DirectionX::LEFT;

		m_currVelocity.x -= m_acceleration * frameTime;
		if (abs(m_currVelocity.x) > m_maxVelocity)
			m_currVelocity.x = -m_maxVelocity;
		break;
	case DirectionX::RIGHT:
		m_movedManuallyX = true;
		m_currDirectionX = DirectionX::RIGHT;

		m_currVelocity.x += m_acceleration * frameTime;
		if (abs(m_currVelocity.x) > m_maxVelocity)
			m_currVelocity.x = m_maxVelocity;
		break;
	}

	switch (dirY)
	{
	case DirectionY::UP:
		m_movedManuallyY = true;
		m_currDirectionY = DirectionY::UP;

		m_currVelocity.y -= m_acceleration * frameTime;
		if (abs(m_currVelocity.y) > m_maxVelocity)
			m_currVelocity.y = -m_maxVelocity;
		break;
	case DirectionY::DOWN:
		m_movedManuallyY = true;
		m_currDirectionY = DirectionY::DOWN;

		m_currVelocity.y += m_acceleration * frameTime;
		if (abs(m_currVelocity.y) > m_maxVelocity)
			m_currVelocity.y = m_maxVelocity;
		break;
	}
}

void Component_Movement::move(sf::Vector2f newVelocity, const float& frameTime)
{
	m_currVelocity = newVelocity;
	m_sprite->move(m_currVelocity * frameTime);
}
