#include "Entity.hpp"

/////////////////////////////////////////////////
// 
//		PROTECTED METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Update

void Entity::move(const float& frameTime, const float dirX, const float dirY)
{
	m_rectShape.move(dirX * m_speed * frameTime, dirY * m_speed * frameTime);
}

void Entity::handleInput(const float& frameTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		move(frameTime, 0.f, -1.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		move(frameTime, -1.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		move(frameTime, 0.f, 1.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		move(frameTime, 1.f, 0.f);
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



//-----------------------------------------------
//		Render
//

void Entity::render(std::shared_ptr<sf::RenderTarget> renderTarget)
{
	renderTarget->draw(m_rectShape);
}
