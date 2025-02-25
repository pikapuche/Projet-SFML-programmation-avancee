#include "Boss.hpp"

Boss::Boss() : Enemy("???", 1400, 625, 240) {}
void Boss::attack(Entities& target) {
	int damage = 35;
	target.losePV(damage);
	cout << target.getHealth() << " PV" << endl << endl;
	cout << E_name << "lance une attaque sur " << target.getName() << " lui infligeant " << damage << " points de degats " << endl << endl;
}