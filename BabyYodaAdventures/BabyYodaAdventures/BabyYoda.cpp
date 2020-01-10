#include "BabyYoda.hpp"

/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

void BabyYoda::initComponents()
{
	initComponentMovement(300.f); // TODO: loading from config
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

BabyYoda::BabyYoda(const float& startX, const float& startY, shared<sf::Texture>& texture)
{
	initTextures(texture);
	initSprite(startX, startY);
	initComponents();
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
