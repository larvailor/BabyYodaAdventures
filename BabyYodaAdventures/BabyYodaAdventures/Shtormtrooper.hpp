#ifndef SHTORMTROOPER_HPP
#define SHTORMTROOPER_HPP

#include "Entity.hpp"

class Shtormtrooper : public Entity
{
private:
	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	shared<Entity> m_goalEntity;

	sf::Vector2f m_currVelocity;

	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Update
	//

	void initSprite(const float& startX, const float& startY);
	void calculateVelocity(const sf::Vector2f& currPos, const sf::Vector2f& goalPos, float maxVelocity);

	//-----------------------------------------------
	//		Update
	//

	void updateComponents(const float& frameTime);
	void updateComponentMovement(const float& frameTime);
	void updateComponentHitbox();

public:
	/////////////////////////////////////////////////
	// 
	//		VARIABLES
	//
	/////////////////////////////////////////////////

	unsigned m_hp; // TODO: add to Component_Attributes

	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////


	//-----------------------------------------------
	//		Constructors
	//

	Shtormtrooper(sf::Vector2f startPos, shared<sf::Texture>& textureSheet, shared<Entity>& goalEntity);

	//-----------------------------------------------
	//		Destructors
	//

	~Shtormtrooper();

	//-----------------------------------------------
	//		Update
	//

	void update(const float& frameTime);

	//-----------------------------------------------
	//		Render
	//

	void render(shared<sf::RenderTarget> renderTarget = nullptr);
};

#endif
