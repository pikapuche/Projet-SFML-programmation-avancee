#include "Entities.hpp"

class Enemy : public Entities {
protected:
	string E_name;
	int E_CoordX, E_CoordY;
	int E_health;
	bool E_isAlive = true;



	bool isAttacking = false;
	bool SoundAttack = false;
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
	bool isAttacking2 = false;
	bool SoundAttack2 = false;
	bool isHealing = false;
	int countAnimAtk2 = 0;

public:
	Enemy(string n, int CX, int CY, int h);

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