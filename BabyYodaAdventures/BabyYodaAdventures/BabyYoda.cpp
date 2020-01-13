#include "BabyYoda.hpp"

#include "Config_Scene_Game.hpp"
#include "Directions.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

void BabyYoda::initSprite(const float& startX, const float& startY)
{
	Entity::initSprite(startX, startY);
	m_sprite->setScale(0.5f, 0.5f);
}



//-----------------------------------------------
//		Update
//


void BabyYoda::updateComponents(const float& frameTime)
{
	updateComponentMovement(frameTime);
	updateComponentAnimation(frameTime);
}

void BabyYoda::updateComponentMovement(const float& frameTime)
{
	m_componentMovement->update(frameTime);
}

void BabyYoda::updateComponentAnimation(const float& frameTime)
{
	static DirectionX dirX;
	static DirectionY dirY;

	dirX = m_componentMovement->getCurrDirectionX();
	dirY = m_componentMovement->getCurrDirectionY();

	if (dirX == DirectionX::NONE && dirY == DirectionY::NONE)
		m_componentAnimation->update("IDLE", frameTime);
	else if (dirX == DirectionX::LEFT)
		m_componentAnimation->update("MOVING_LEFT", frameTime);
	else if (dirX == DirectionX::RIGHT)
		m_componentAnimation->update("MOVING_RIGHT", frameTime);
	else if (dirY == DirectionY::UP)
		m_componentAnimation->update("MOVING_UP", frameTime);
	else if (dirY == DirectionY::DOWN)
		m_componentAnimation->update("MOVING_DOWN", frameTime);
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
	initTextureSheet(textureSheet);
	initSprite(startX, startY);
	createComponentMovement(300.f, 0.05f, 0.05f); // TODO: loading from config
	createComponentAnimation(SCENE_GAME_BABY_YODA_ANIMATIONS_PATH);
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

void BabyYoda::move(const DirectionX& dirX, const DirectionY& dirY, const float& frameTime)
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
