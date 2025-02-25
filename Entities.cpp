#include "Entities.hpp"

Entities::Entities(bool A) : e_health(), e_damage(), e_CoordX(), e_CoordY(), e_isAlive(A) {}

void Entities::printInfos() {
	cout << "Degats : " << e_damage << "Coordonnees : " << e_CoordX << ", " << e_CoordY << endl << endl;
}

int Entities::losePV(int damage) {
	e_health -= damage;
	if (e_health <= 0) {
		e_health = 0;
		e_isAlive = false;
	}
	return e_health;
}
int Entities::getHealth() {
	return e_health;
}
int Entities::getCoordX() {
	return e_CoordX;
}
int Entities::getCoordY() {
	return e_CoordY;
}
string Entities::getName() {
	return e_name;
}
bool Entities::getAlive() {
	return e_isAlive;
}
int Entities::heal() {
	e_health += 30;
	return e_health;
}
int Entities::setHealth(int pv) {
	e_health = pv;
	return e_health;
}
int Entities::HealthReset(int pv) {
	e_health = pv;
	return e_health;
}
bool Entities::LifeReset() {
	e_isAlive = true;
	return e_isAlive;
}