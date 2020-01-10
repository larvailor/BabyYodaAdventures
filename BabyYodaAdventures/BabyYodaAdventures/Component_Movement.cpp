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
	m_movedManuallyY(false)
{
	m_acceleration = m_maxVelocity / reachMaxVelocityTime;
	m_deceleration = m_maxVelocity / reachZeroVelocityTime;
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

sf::Vector2f Component_Movement::getVelocity() const
{
	return m_currVelocity;
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
				m_currVelocity.x = 0.f;
		}
		else
		{
			m_currVelocity.x -= m_deceleration * frameTime;
			if (m_currVelocity.x < 0)
				m_currVelocity.x = 0.f;
		}
	}

	if (!m_movedManuallyY && m_currVelocity.y != 0.f)
	{
		if (m_currVelocity.y < 0)
		{
			m_currVelocity.y += m_deceleration * frameTime;
			if (m_currVelocity.y > 0)
				m_currVelocity.y = 0.f;
		}
		else
		{
			m_currVelocity.y -= m_deceleration * frameTime;
			if (m_currVelocity.y < 0)
				m_currVelocity.y = 0.f;
		}
	}

	m_sprite->move(m_currVelocity * frameTime);

	m_movedManuallyX = false;
	m_movedManuallyY = false;
}



//-----------------------------------------------
//		Input handling
//

void Component_Movement::move(const DirectionXY& dirX, const DirectionXY& dirY, const float& frameTime)
{
	// Acceleration
	switch (dirX)
	{
	case DirectionXY::LEFT:
		m_movedManuallyX = true;

		m_currVelocity.x -= m_acceleration * frameTime;
		if (abs(m_currVelocity.x) > m_maxVelocity)
			m_currVelocity.x = -m_maxVelocity;
		break;
	case DirectionXY::RIGHT:
		m_movedManuallyX = true;

		m_currVelocity.x += m_acceleration * frameTime;
		if (abs(m_currVelocity.x) > m_maxVelocity)
			m_currVelocity.x = m_maxVelocity;
		break;
	}

	switch (dirY)
	{
	case DirectionXY::UP:
		m_movedManuallyY = true;

		m_currVelocity.y -= m_acceleration * frameTime;
		if (abs(m_currVelocity.y) > m_maxVelocity)
			m_currVelocity.y = -m_maxVelocity;
		break;
	case DirectionXY::DOWN:
		m_movedManuallyY = true;

		m_currVelocity.y += m_acceleration * frameTime;
		if (abs(m_currVelocity.y) > m_maxVelocity)
			m_currVelocity.y = m_maxVelocity;
		break;
	}
}
