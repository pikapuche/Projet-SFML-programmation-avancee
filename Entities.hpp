#include "stdafx.hpp"

class Entities {
protected:
	string e_name;
	int e_damage;
	int e_CoordX, e_CoordY;
	int e_health;
	bool e_isAlive = true;

public:
	Entities(bool A) : e_health(), e_damage(), e_CoordX(), e_CoordY(), e_isAlive(A) {}

	void printInfos();

	virtual void attack(Entities& target) = 0;

	virtual int losePV(int damage);

	virtual int getHealth();

	virtual int getCoordX();

	virtual int getCoordY();

	virtual string getName();

	virtual bool getAlive();

	virtual int heal();

	virtual int setHealth(int pv);

	virtual int HealthReset(int pv);

	virtual bool LifeReset();
};