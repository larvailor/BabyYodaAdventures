#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Component_Movement.hpp"
#include "Component_Animation.hpp"

class Entity
{
protected:
	/////////////////////////////////////////////////
	// 
	//		VARIABLES
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Sprites
	//

	shared<sf::Sprite> m_sprite;

	//-----------------------------------------------
	//		Position
	//

	float m_posX;
	float m_posY;

	//-----------------------------------------------
	//		Components
	//

	unique<Component_Movement> m_componentMovement;
	unique<Component_Animation> m_componentAnimation;

	//-----------------------------------------------
	//		Resources
	//

		// Textures

	shared<sf::Texture> m_textureSheet;

	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Initialization
	//

	virtual void initTextureSheet(shared<sf::Texture>& texture);
	virtual void initSprite(const float& startX, const float& startY);
	/* TODO: loading from .ini file */
	virtual void createComponentMovement(const float maxVelocity, const float acceleration, const float deceleration);
	virtual void createComponentAnimation(std::string pathToAnimationsIni);

public:
	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	Entity();

	//-----------------------------------------------
	//		Destructors
	//

	virtual ~Entity();

	//-----------------------------------------------
	//		Accessors
	//

		// Getters

	virtual float getX() const;
	virtual float getY() const;
	virtual sf::Vector2f getPos() const;

		// Setters

	virtual void setX(const float& x);
	virtual void setY(const float& y);
	virtual void setPos(const sf::Vector2f& pos);

	//-----------------------------------------------
	//		Update
	//

	virtual void update(const float& frameTime) = 0;
	virtual void move(const DirectionX& dirX, const DirectionY& dirY, const float& frameTime);

	//-----------------------------------------------
	//		Render
	//

	virtual void render(shared<sf::RenderTarget> renderTarget = nullptr) = 0;
};

#endif
