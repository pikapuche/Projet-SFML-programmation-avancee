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