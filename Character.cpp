#include "Character.hpp"

Character::Character(string n, int CX, int CY, int h) : c_name(n), c_CoordX(CX), c_CoordY(CY), c_health(h), Entities(true) {}

void Character::attack(Entities& target) {}

int Character::losePV(int damage) {
	c_health -= damage;
	if (c_health <= 0) {
		c_health = 0;
		c_isAlive = false;
	}
	return c_health;
}
int Character::getHealth() {
	return c_health;
}
int Character::getCoordX() {
	return c_CoordX;
}
int Character::getCoordY() {
	return c_CoordY;
}
string Character::getName() {
	return c_name;
}
bool Character::getAlive() {
	return c_isAlive;
}
int Character::heal() {
	c_health += 35;
	return c_health;
}
int Character::setHealth(int pv) {
	c_health = pv;
	return c_health;
}
int Character::HealthReset(int pv) {
	c_health = pv;
	return c_health;
}
bool Character::LifeReset() {
	c_isAlive = true;
	return c_isAlive;
}