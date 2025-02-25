#include "Entities.hpp"

class Character : public Entities {
protected:
	string c_name;
	int c_CoordX, c_CoordY;
	int c_health;
	bool c_isAlive = true;
	int damage = 40;



	bool isAttacking = false;
	bool SoundAttack = false;
	bool AttackMode = false;
	bool isHealing = false;
	bool SoundHeal = false;
	bool isHit = false;
	bool SoundHit = false;
	bool isDead = false;
	bool printBody = false;
	bool readyToPlay = false;
	int countAnimAtk = 0;
	int countAnimHeal = 0;
	int countAnimHit = 0;
	int countAnimDeath = 0;
	int DeathCount = 0;

public:
	Character(string n, int CX, int CY, int h);

	void attack(Entities& target) override;

	int losePV(int damage) override;
	int getHealth() override;
	int getCoordX() override;
	int getCoordY() override;
	string getName() override;
	bool getAlive() override;
	int heal() override;
	int setHealth(int pv) override;
	int HealthReset(int pv) override;
	bool LifeReset();
};