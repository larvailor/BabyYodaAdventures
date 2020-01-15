#ifndef MAGMABALL_HPP
#define MAGMABALL_HPP

#include "Entity.hpp"

class MagmaBall : public Entity
{
private:
	/////////////////////////////////////////////////
	// 
	//		VARIABLES
	//
	/////////////////////////////////////////////////

	float m_velocityX;
	float m_velocityY;

	/////////////////////////////////////////////////
	// 
	//		Methods
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Initialization
	//

	sf::Vector2f calculateSpeed(const sf::Vector2f& playerPos, const sf::Vector2f& mousePos, float startSpeed);


	//-----------------------------------------------
	//		Update
	//

	void updateComponents(const float& frameTime);
	void updateComponentMovement(const float& frameTime);
	void updateComponentHitbox();
	void updateComponentAnimation(const float& frameTime);

public:
	/////////////////////////////////////////////////
	// 
	//		Methods
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	MagmaBall(sf::Vector2f playerPos, sf::Vector2f mousePos, shared<sf::Texture>& textureSheet);

	//-----------------------------------------------
	//		Destructors
	//

	~MagmaBall();

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
