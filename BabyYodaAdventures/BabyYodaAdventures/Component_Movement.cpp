#include "Component_Movement.hpp"

/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Component_Movement::Component_Movement(float maxVelocity, shared<sf::Sprite>& sprite) :
	m_maxVelocity(maxVelocity),
	m_sprite(sprite)
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

sf::Vector2f Component_Movement::getVelocity() const
{
	return m_velocity;
}



//-----------------------------------------------
//		Update
//

void Component_Movement::update(const float& frameTime)
{
	
}



//-----------------------------------------------
//		Else
//

void Component_Movement::move(const float dirX, const float dirY, const float& frameTime)
{
	m_velocity.x = m_maxVelocity * dirX;
	m_velocity.y = m_maxVelocity * dirY;

	m_sprite->move(m_velocity * frameTime);
}
