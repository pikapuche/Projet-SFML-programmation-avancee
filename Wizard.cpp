#include "Wizard.hpp"

Wizard::Wizard() : Character("William l'intervenant", 225, 625, 500) {}
void Wizard::attack(Entities& target) {
	int damage = 40;
	target.losePV(damage);
	cout << target.getHealth() << " PV" << endl << endl;
	cout << c_name << " lance une attaque sur " << target.getName() << " lui infligeant " << damage << " points de degats " << endl << endl;
}