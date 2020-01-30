#ifndef BABY_YODA_HPP
#define BABY_YODA_HPP

#include "Entity.hpp"

class BabyYoda : public Entity
{
private:
	/////////////////////////////////////////////////
	// 
	//		Methods
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Initialization
	//

	void initSprite(const float& startX, const float& startY);

	//-----------------------------------------------
	//		Update
	//

	void updateComponents(const float& frameTime);
	void updateComponentMovement(const float& frameTime);
	void updateComponentHitbox();
	void updateComponentAnimation(const float& frameTime);

public:
	// TODO: move to the attribute component
	unsigned int m_hp;
	unsigned int m_killsCounter;

	/////////////////////////////////////////////////
	// 
	//		Methods
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	BabyYoda(const float& startX, const float& startY, shared<sf::Texture>& textureSheet);

	//-----------------------------------------------
	//		Destructors
	//

	~BabyYoda();

	//-----------------------------------------------
	//		Update
	//

	void update(const float& frameTime);
	void move(const DirectionX& dirX, const DirectionY& dirY, const float& frameTime);

	//-----------------------------------------------
	//		Render
	//

	void render(shared<sf::RenderTarget> renderTarget = nullptr);
};

#endif
