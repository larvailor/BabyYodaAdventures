#include "BabyYoda.hpp"

/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

BabyYoda::BabyYoda(const float& startX, const float& startY, shared<sf::Texture>& texture) :
	Entity(startX, startY, texture)
{
	m_speed = 300.f; // TODO: load from config
	m_sprite->setScale(0.4f, 0.4f);
}



//-----------------------------------------------
//		Destructors
//

BabyYoda::~BabyYoda()
= default;



//-----------------------------------------------
//		Update
//

void BabyYoda::update(const float& frameTime)
{
	// TBD
}



//-----------------------------------------------
//		Render
//

void BabyYoda::render(shared<sf::RenderTarget> renderTarget)
{
	renderTarget->draw(*m_sprite);
}
