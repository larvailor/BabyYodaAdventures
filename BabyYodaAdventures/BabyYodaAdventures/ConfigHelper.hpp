/**
	A configuration file that contains global variables
*/

#ifndef CONFIG_HELPER_HPP
#define CONFIG_HELPER_HPP

//-----------------------------------------------
//		Game
//

constexpr auto WINDOW_CONFIG_PATH = "Config/window.ini";
constexpr auto SUPPORTED_KEYS_CONFIG_PATH = "Config/SupportedKeys.ini";



//-----------------------------------------------
//		Scene_GameScene
//

constexpr auto SCENE_GAME_KEY_BINDS_PATH = "Config/Scenes/Game/Scene_Game_KeyBinds.ini";
constexpr auto SCENE_GAME_SPRITES_DIR_PATH = "Resources/Images/Game/Sprites";
constexpr auto SCENE_GAME_BABY_YODA_SPRITE_PATH = "Resources/Images/Game/Sprites/BabyYoda/Idle/BabyYoda_idle_1.png";



//-----------------------------------------------
//		Scene_MainMenu
//

constexpr auto SCENE_MAIN_MENU_KEY_BINDS_PATH = "Config/Scenes/MainMenu/Scene_MainMenu_KeyBinds.ini";
constexpr auto SCENE_MAIN_MENU_FONT_PATH = "Resources/Fonts/Polybius1981.ttf";
constexpr auto SCENE_MAIN_MENU_BUTTONS_PATH = "Config/Scenes/MainMenu/Scene_MainMenu_Buttons.ini";
constexpr auto SCENE_MAIN_MENU_BACKGROUND_PATH = "Resources/Images/MainMenu/Scene_MainMenu_Background_space.png";

#endif
