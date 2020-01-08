#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <fstream>

#include "Types.hpp"

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

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

	unique<sf::Sprite> m_sprite;

	//-----------------------------------------------
	//		Position
	//

	float m_posX;
	float m_posY;

	//-----------------------------------------------
	//		Speed
	//

	float m_speed;

	//-----------------------------------------------
	//		Resources
	//

		// Textures

	shared<sf::Texture> m_texture;


	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Initialization
	//

	virtual void initTextures(shared<sf::Texture>& texture);
	virtual void initSprite(const float& startX, const float& startY);

public:
	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	Entity(const float& startX, const float& startY, shared<sf::Texture>& texture);

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
	virtual void move(const float& frameTime, const float dirX, const float dirY);

	//-----------------------------------------------
	//		Render
	//

	virtual void render(shared<sf::RenderTarget> renderTarget = nullptr) = 0;
};

#endif
