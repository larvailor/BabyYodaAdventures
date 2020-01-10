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
	initComponentMovement(300.f, 0.05f, 0.05f); // TODO: loading from config
	m_sprite->setScale(0.5f, 0.5f);
}



//-----------------------------------------------
//		Update
//

void BabyYoda::updateComponents(const float& frameTime)
{
	m_componentMovement->update(frameTime);
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
	updateComponents(frameTime);
}

void BabyYoda::move(const DirectionXY& dirX, const DirectionXY& dirY, const float& frameTime)
{
	Entity::move(dirX, dirY, frameTime);
}



//-----------------------------------------------
//		Render
//

void BabyYoda::render(shared<sf::RenderTarget> renderTarget)
{
	renderTarget->draw(*m_sprite);
}
