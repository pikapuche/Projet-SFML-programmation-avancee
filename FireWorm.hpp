#include "Enemy.hpp"

class FireWorm : public Enemy {
public:
	FireWorm() : Enemy("Fire Worm, THE ELDEN LORD", 925, 650, 75) {}
	void attack(Entities& target) override {
		int damage = 10;
		target.losePV(damage);
		cout << target.getHealth() << " PV" << endl << endl;
		cout << E_name << " lance une attaque sur " << target.getName() << " lui infligeant " << damage << " points de degats " << endl << endl;
	}

};