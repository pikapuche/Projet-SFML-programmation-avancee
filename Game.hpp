#include "Character.hpp"
#include "Enemy.hpp"

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

#pragma region Initialisation

	////////// Texture / Sprite ///////////

	// Background
	sf::Texture background_texture;
	sf::Sprite sprite_background;

	// Personnage
	sf::Texture perso_texture;
	sf::Sprite perso_sprite; // ce sprite va etre le main sprite il faut juste changer la texture quand on fait une action

	sf::Texture perso_texture_Attack;
	sf::Texture perso_texture_Heal;
	sf::Texture perso_texture_Hit;
	sf::Texture perso_texture_Death;

	// FireWorm
	sf::Texture fireWorm_texture;
	sf::Sprite fireWorm_sprite;

	sf::Texture fireWorm_texture_Attack;
	sf::Texture fireWorm_texture_Hit;
	sf::Texture fireWorm_texture_Death;

	// EvilWizard
	sf::Texture evilWizard_texture;
	sf::Sprite evilWizard_sprite;

	sf::Texture evilWizard_texture_Attack;
	sf::Texture evilWizard_texture_Heal;
	sf::Texture evilWizard_texture_Hit;
	sf::Texture evilWizard_texture_Death;

	// Boss
	sf::Texture boss_texture;
	sf::Sprite boss_sprite;

	sf::Texture boss_texture_Attack;
	sf::Texture boss_texture_Attack2;
	sf::Texture boss_texture_Hit;
	sf::Texture boss_texture_Death;

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

	////////// Animation ///////////
	sf::Vector2i c_anim;
	sf::Vector2i c_anim_Attack;
	sf::Vector2i c_anim_Heal;
	sf::Vector2i c_anim_Hit;
	sf::Vector2i c_anim_Death;

	sf::Vector2i f_anim;
	sf::Vector2i f_anim_Attack;
	sf::Vector2i f_anim_Hit;
	sf::Vector2i f_anim_Death;

	sf::Vector2i e_anim;
	sf::Vector2i e_anim_Attack;
	sf::Vector2i e_anim_Hit;
	sf::Vector2i e_anim_Heal;
	sf::Vector2i e_anim_Death;

	sf::Vector2i b_anim;
	sf::Vector2i b_anim_Attack;
	sf::Vector2i b_anim_Attack2;
	sf::Vector2i b_anim_Hit;
	sf::Vector2i b_anim_Death;
	////////////////////////////////

	////////// Music ///////////
	sf::Music menuMusic;
	sf::Music endWinMusic;
	sf::Music endLoseMusic;
	sf::Music fightMusic;
	///////////////////////////

	////////// Sound ///////////
	sf::SoundBuffer wizardAttack;
	sf::Sound soundWizardAttack;

	sf::SoundBuffer Heal;
	sf::Sound soundHeal;

	sf::SoundBuffer fireWormAttack;
	sf::Sound soundFireWormAttack;


	sf::SoundBuffer evilWizardAttack;
	sf::Sound soundEvilWizardAttack;


	sf::SoundBuffer bossAttack;
	sf::Sound soundBossAttack;
	////////////////////////////
	
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








	///////////////////////////

#pragma endregion Initialisation

public : 

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