#ifndef SCENE_HPP
#define SCENE_HPP

#include "Types.hpp"

#include "BabyYoda.hpp"

#include "Button.hpp"

class Scene
{
protected:
	/////////////////////////////////////////////////
	// 
	//		VARIABLES
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Render targets
	//

	/* A shared_ptr to a window on which the scene is drawn */
	shared<sf::RenderWindow> m_renderWindow;

	//-----------------------------------------------
	//		Keys
	//

	/* A map of keys that are used by the scene */
	std::map<std::string, sf::Keyboard::Key> m_keyBinds;

	/* A global map of all supported keys */
	shared_map<std::string, sf::Keyboard::Key> m_supportedKeys;

	//-----------------------------------------------
	//		Mouse positions
	//

	/* Mouse position on the native screen */
	sf::Vector2i m_mousePosScreen;

	/* Mouse position inside the window */
	sf::Vector2i m_mousePosWindow;

	/* Mouse position on the view (example: a big tile map) */
	sf::Vector2f m_mousePosView;

	//-----------------------------------------------
	//		Scene state
	//

	/* Indicates should the scene be closed or not */
	bool m_quit = false;

	/* A global stack that is used for managing scenes */
	shared_stack<shared<Scene>> m_scenes;

	//-----------------------------------------------
	//		Resources
	//
	
		// Textures
	
	/**
		A map of textures that are used by the scene 
		TODO: implement
	*/
	// std::map<std::string, shared_map<std::string, std::map<std::string, std::vector<sf::Texture>>>> m_textures;
	std::map<std::string, shared<sf::Texture>> m_textures;

		// Fonts

	/**
		A font that is used by the scene.
		TODO: make a map of fonts
	*/
	shared<sf::Font> m_font;

		// Buttons

	/* A map of buttons that are used by the scene*/
	std::map<std::string, shared<Button>> m_buttons;



	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Initialization
	//

	/**
		Loads all key binds for specific scene
		and creates an std::map of supported keys and their codes
	*/
	virtual void initKeyBinds(std::string pathToKeyBinsIni);
	virtual void initFont(std::string pathToFont);

	/**
		Loads all buttons that are used by the scene.
		Should be called after fonts were initialized
	*/
	virtual void initButtons(std::string pathToButtonsIni);

	/**
		TODO: rebuild and make generic with TexturesLoader
	*/
	virtual void initTextures();

	//-----------------------------------------------
	//		Update
	//

	virtual void handleInput(const float& frameTime) = 0;
	virtual void updateMousePositions();
	virtual void updateButtons();

	//-----------------------------------------------
	//		Managing scene
	//

	virtual void quitScene();
	virtual void renderButtons(shared<sf::RenderTarget>& renderTarget);

public:
	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	Scene(
		shared<sf::RenderWindow>& renderWindow,
		shared_stack<shared<Scene>>& scenes,
		const shared_map<std::string, sf::Keyboard::Key>& supportedKeys
	);

	//-----------------------------------------------
	//		Destructors
	//

	virtual ~Scene();

	//-----------------------------------------------
	//		Accessors
	//

		// Getters

	bool needToBeClosed() const;

	//-----------------------------------------------
	//		Update
	//

	virtual void update(const float& frameTime) = 0;

	//-----------------------------------------------
	//		Render
	//

	virtual void render(shared<sf::RenderTarget> renderTarget = nullptr) = 0;
};

#endif
