#include "Component_Hitbox.hpp"

/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Component_Hitbox::Component_Hitbox(shared<sf::Sprite>& sprite, float offsetX, float offsetY, float width, float height) :
	m_sprite(sprite),
	m_offsetX(offsetX),
	m_offsetY(offsetY),
	m_width(width),
	m_height(height)
{
	m_hitbox.setPosition(
		sf::Vector2f(
			m_sprite->getPosition().x + offsetX,
			m_sprite->getPosition().y + offsetY
		)
	);
	m_hitbox.setSize(sf::Vector2f(width, height));
	m_hitbox.setFillColor(sf::Color::Transparent);
	m_hitbox.setOutlineThickness(1.f);
	m_hitbox.setOutlineColor(sf::Color::Green);
}



//-----------------------------------------------
//		Destructors
//

Component_Hitbox::~Component_Hitbox()
= default;



//-----------------------------------------------
//		Update
//

void Component_Hitbox::update()
{
	m_hitbox.setPosition(
		sf::Vector2f(
			m_sprite->getPosition().x + m_offsetX,
			m_sprite->getPosition().y + m_offsetY
		)
	);
}



//-----------------------------------------------
//		Render
//

void Component_Hitbox::render(shared<sf::RenderTarget> & renderTarget)
{
	renderTarget->draw(m_hitbox);
}



//-----------------------------------------------
//		Else
//

bool Component_Hitbox::intersects(const sf::FloatRect& rect)
{
	return m_hitbox.getGlobalBounds().intersects(rect) ? true : false;
}
