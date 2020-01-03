#ifndef STATE_HPP
#define STATE_HPP

#include "Entity.hpp"

class State
{
protected:
	/////////////////////
	// Variables
	//

	std::shared_ptr<sf::RenderWindow> m_renderWindow;
	std::map<std::string, int>* m_supportedKeys;
	std::map<std::string, int> m_keyBinds;
	bool m_close;

	// Resources

	std::vector<std::shared_ptr<sf::Texture>> m_textures;
	


	/////////////////////
	// Methods
	//

	// Initialization

	virtual void initKeyBinds() = 0;

	// Udate

	virtual void handleInput(const float& frameTime) = 0;

	// Managing state

	virtual void checkForClose();

public:
	/////////////////////
	// Methods
	//

	// Constructors

	State(std::shared_ptr<sf::RenderWindow> renderWindow, std::map<std::string, int>* supportedKeys);

	// Destructors

	virtual ~State();

	//Accessors
		// getters

	bool needToBeClosed() const;

	// Udate

	virtual void update(const float& frameTime) = 0;

	// Render

	virtual void render(std::shared_ptr<sf::RenderTarget> renderTarget = nullptr) = 0;

	// Managing state

	virtual void finalizeState() = 0;
};

#endif
