#include "Entity.hpp"

/////////////////////////////////////////////////
// 
//		PROTECTED METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Update

void Entity::handleInput(const float& frameTime)
{

}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Entity::Entity()
{
	m_rectShape.setSize(sf::Vector2f(100.f, 100.f));
	m_speed = 500.f;
}



//-----------------------------------------------
//		Destructors
//

Entity::~Entity()
= default;



//-----------------------------------------------
//		Update
//

void Entity::update(const float& frameTime)
{
	handleInput(frameTime);
}


void Entity::move(const float& frameTime, const float dirX, const float dirY)
{
	m_rectShape.move(dirX * m_speed * frameTime, dirY * m_speed * frameTime);
}


//-----------------------------------------------
//		Render
//

void Entity::render(shared<sf::RenderTarget> renderTarget)
{
	renderTarget->draw(m_rectShape);
}
