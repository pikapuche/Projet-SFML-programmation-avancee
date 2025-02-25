#include "EvilWizard.hpp"

EvilWizard::EvilWizard() : Enemy("Omariu, THE LITTLE SHIT", 1125, 755, 150) {}
void EvilWizard::attack(Entities& target) {
	int damage = 20;
	target.losePV(damage);
	cout << target.getHealth() << " PV" << endl << endl;
	cout << E_name << "lance une attaque sur " << target.getName() << " lui infligeant " << damage << " points de degats " << endl << endl;
}