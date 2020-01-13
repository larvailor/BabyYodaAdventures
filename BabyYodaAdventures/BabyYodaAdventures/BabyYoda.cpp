#include "BabyYoda.hpp"

#include "Config_Scene_Game.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Update
//

void BabyYoda::updateComponents(const float& frameTime)
{
	m_componentMovement->update(frameTime);
	m_componentAnimation->update("IDLE", frameTime);
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
	m_sprite->setScale(0.5f, 0.5f);

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
