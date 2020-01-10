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

	void initComponents();

	//-----------------------------------------------
	//		Update
	//

	void updateComponents(const float& frameTime);

public:
	/////////////////////////////////////////////////
	// 
	//		Methods
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	BabyYoda(const float& startX, const float& startY, shared<sf::Texture>& texture);

	//-----------------------------------------------
	//		Destructors
	//

	~BabyYoda();

	//-----------------------------------------------
	//		Update
	//

	void update(const float& frameTime);
	void move(const DirectionXY& dirX, const DirectionXY& dirY, const float& frameTime);

	//-----------------------------------------------
	//		Render
	//

	void render(shared<sf::RenderTarget> renderTarget = nullptr);
};

#endif