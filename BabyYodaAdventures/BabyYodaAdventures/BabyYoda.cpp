#include "BabyYoda.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

void BabyYoda::createComponents()
{
	createComponentMovement(300.f, 0.05f, 0.05f); // TODO: loading from config
	createComponentAnimation(m_texture);

	m_componentAnimation->addAnimation("IDLE", 1.f, 0, 0, 10, 0, 64, 72);
}



//-----------------------------------------------
//		Update
//

void BabyYoda::updateComponents(const float& frameTime)
{
	m_componentMovement->update(frameTime);
	m_componentAnimation->play("IDLE", frameTime);
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

BabyYoda::BabyYoda(const float& startX, const float& startY, shared<sf::Texture>& textureSheet)
{
	initTextures(textureSheet);
	initSprite(startX, startY);
	createComponents();
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
