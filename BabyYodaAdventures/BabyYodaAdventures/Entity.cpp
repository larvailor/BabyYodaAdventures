#include "Entity.hpp"

#include <fstream>

/////////////////////////////////////////////////
// 
//		PROTECTED METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

void Entity::initTextureSheet(shared<sf::Texture>& texture)
{
	m_textureSheet = texture;
}

void Entity::initSprite(const float& startX, const float& startY)
{
	m_sprite = std::make_shared<sf::Sprite>(*m_textureSheet);
	m_sprite->setPosition(startX, startY);
}

void Entity::createComponentMovement(const float maxVelocity, const float reachMaxVelocityTime, const float reachZeroVelocityTime)
{
	m_componentMovement = std::make_unique<Component_Movement>(maxVelocity, reachMaxVelocityTime, reachZeroVelocityTime, m_sprite);
}

void Entity::createComponentAnimation(std::string pathToAnimationsIni)
{
	m_componentAnimation = std::make_unique<Component_Animation>(m_sprite, m_textureSheet);

	std::ifstream ifs;
	ifs.open(pathToAnimationsIni);
	if (ifs.is_open())
	{
		std::string animationKey;
		float animationTime;
		int startFrameX, startFrameY, framesX, framesY;
		int width, height;

		while (!ifs.eof())
		{
			std::getline(ifs, animationKey);
			// an empty line used as a delimiter between animations
			if (animationKey.empty()) { continue; }

			ifs >> animationTime;
			ifs >> startFrameX >> startFrameY >> framesX >> framesY;
			ifs >> width >> height;

			m_componentAnimation->addAnimation(animationKey, animationTime, startFrameX, startFrameY, framesX, framesY, width, height);
		}
	}
	else
	{
		std::cout << "ERROR::Entity::createComponentAnimation failed to load animations config" << pathToAnimationsIni << std::endl;
	}
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Entity::Entity() :
	m_posX(0),
	m_posY(0)
{

}



//-----------------------------------------------
//		Destructors
//

Entity::~Entity()
= default;



//-----------------------------------------------
//		Accessors
//

	// Getters

float Entity::getX() const
{
	return m_sprite ? m_sprite->getPosition().x : 0.f;
}

float Entity::getY() const
{
	return m_sprite ? m_sprite->getPosition().y : 0.f;
}

sf::Vector2f Entity::getPos() const
{
	return m_sprite ? m_sprite->getPosition() : sf::Vector2f(0, 0);
}

	// Setters

void Entity::setX(const float& x)
{
	if (m_sprite)
		m_sprite->setPosition(x, m_posY);
}

void Entity::setY(const float& y)
{
	if (m_sprite)
		m_sprite->setPosition(m_posX, y);
}

void Entity::setPos(const sf::Vector2f& pos)
{
	if (m_sprite)
		m_sprite->setPosition(pos);
}



//-----------------------------------------------
//		Update
//

void Entity::move(const DirectionX& dirX, const DirectionY& dirY, const float& frameTime)
{
	if (m_sprite && m_componentMovement)
		m_componentMovement->move(dirX, dirY, frameTime);
}
