#include "Enemy.hpp"

Enemy::Enemy(string n, int CX, int CY, int h) : E_name(n), E_CoordX(CX), E_CoordY(CY), E_health(h), Entities(true) {}

void Enemy::attack(Entities& target) {}

int Enemy::losePV(int damage) {
	E_health -= damage;
	if (E_health <= 0) {
		E_health = 0;
		E_isAlive = false;
	}
	return E_health;
}
int Enemy::getHealth() {
	return E_health;
}
int Enemy::getCoordX() {
	return E_CoordX;
}
int Enemy::getCoordY() {
	return E_CoordY;
}
string Enemy::getName() {
	return E_name;
}
bool Enemy::getAlive() {
	return E_isAlive;
}
int Enemy::heal() {
	E_health += 30;
	return E_health;
}
int Enemy::setHealth(int pv) {
	E_health = pv;
	return E_health;
}
int Enemy::HealthReset(int pv) {
	E_health = pv;
	return E_health;
}
bool Enemy::LifeReset() {
	E_isAlive = true;
	return E_isAlive;
}