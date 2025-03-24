#include "Entities.hpp"

class Game {
private : 
	int countMenu = 0;
	int countFirstMenu = 0;
	int gameCount = 0;
	int stopMusic = 0;
	bool infoBoxB = false;
	bool menuExit = false;
	int quiSoigner = 0;
	int countPlay = 0;
	int menuCOuntPlay = 0;
	bool menuEnter = false;
	int endCount = 0;
	bool restartGame = false;
	int frameLimit = 60;

#pragma region Initialisation

	////////// Texture / Sprite ///////////

	// Background
	sf::Texture background_texture;
	sf::Sprite sprite_background;

	// Menu 
	sf::Texture background_texture_Menu;
	sf::Sprite sprite_background_Menu;

	sf::Texture background_texture_Menu2;
	sf::Sprite sprite_background_Menu2;

	sf::Texture background_texture_Menu3;
	sf::Sprite sprite_background_Menu3;

	sf::Texture background_texture_Menu4;
	sf::Sprite sprite_background_Menu4;

	sf::Texture background_texture_Menu5;
	sf::Sprite sprite_background_Menu5;

	sf::Texture background_texture_Menu6;
	sf::Sprite sprite_background_Menu6;

	////////////////////////////////

	////////// Music ///////////
	sf::Music menuMusic;
	sf::Music endWinMusic;
	sf::Music endLoseMusic;
	sf::Music fightMusic;
	///////////////////////////

		////////// Sound ///////////
	sf::SoundBuffer bufferAttack;
	sf::Sound soundAttack;
	
	////////// Font / Text ///////////
	sf::Font fontMenu;
	sf::Text title_Menu;
	sf::Text start_Menu;
	sf::Text settings_Menu;
	sf::Text quit_Menu;
	sf::Text textAtk;
	sf::Text textMenuWorm;
	sf::Text textMenuEvilWizard;
	sf::Text textMenuBoss;
	sf::Text textHeal;
	sf::Text textSkip;

	sf::Text UI_Character;
	sf::Text UI_Character_PV;
	sf::Text UI_Character_PV2;
	sf::Text UI_Worm;
	sf::Text UI_Worm_PV;
	sf::Text UI_Worm_PV2;
	sf::Text UI_Evil;
	sf::Text UI_Evil_PV;
	sf::Text UI_Evil_PV2;
	sf::Text UI_Boss;
	sf::Text UI_Boss_PV;
	sf::Text UI_Boss_PV2;

	sf::Text textInfoBox;
	sf::Text textWin;
	sf::Text textDefeat;
	sf::Text quit_EndText;
	sf::Text restart_EndText;
	sf::Text quit_settings_Window_Text;
	sf::Text settings_music;
	sf::Text settings_menu_music;
	sf::Text text_menu_music;
	sf::Text settings_game_music;
	sf::Text text_game_music;
	sf::Text settings_game_sound;
	sf::Text text_game_sound;

	////////// RectangleShape / CircleShape ///////////

	sf::RectangleShape start_Menu_RectangleShape;
	sf::RectangleShape settings_Menu_RectangleShape;
	sf::RectangleShape quit_Menu_RectangleShape;
	sf::RectangleShape menuBackground;
	sf::RectangleShape menuAtk;
	sf::RectangleShape menuWhoAtk;
	sf::RectangleShape menuWorm;
	sf::RectangleShape menuEvilWizard;
	sf::RectangleShape menuBoss;
	sf::RectangleShape menuHeal;
	sf::RectangleShape menuSkip;
	sf::RectangleShape infoBox;
	sf::RectangleShape quit_End;
	sf::RectangleShape restart_End;
	sf::RectangleShape settings_Window;

	///////////////////////////

#pragma endregion Initialisation

public : 

	vector<unique_ptr<Entities>> vector_Entities;

	unique_ptr<Entities> Character = make_unique<Entities>("William l'intervenant", 500, 25, 225, 625); // (string n, int life, int dmg, int X, int Y, bool A)
	unique_ptr<Entities> Worm = make_unique<Entities>("Fire Worm, THE ELDEN LORD", 75, 10, 925, 650);
	unique_ptr<Entities> EvilWizard = make_unique<Entities>("Omariu, THE LITTLE SHIT", 150, 20, 1125, 755);
	unique_ptr<Entities> Boss = make_unique<Entities>("???", 425, 25, 1400, 625);

	struct Settings {

		bool inSettings = false;
		bool inMenuMusic = false;
		float volumeMenuMusic = 25.f;

		bool inGameMusic = false;
		float volumeGameMusic = 25.f;

		bool inGameSound = false;
		float volumeGameSound = 25.f;

		bool loseMusic = false;
		bool winMusic = false;

		int settingsCountPlay = 0;

	}; Settings Settings_S;

	void initAll();

	void run();
};