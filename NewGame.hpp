#include "Entities.hpp"

class Game {
private:
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

	////////// Sound ///////////
	sf::SoundBuffer bufferAttack;
	sf::Sound soundAttack;

public:

	vector<unique_ptr<Entities>> vector_Entities;

	unique_ptr<Entities> Worm = make_unique<Entities>("Fire Worm, THE ELDEN LORD", 75, 10);
	unique_ptr<Entities> EvilWizard = make_unique<Entities>("Omariu, THE LITTLE SHIT", 150, 20);
	unique_ptr<Entities> Boss = make_unique<Entities>("???", 425, 25);

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