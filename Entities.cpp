#include "Entities.hpp"

Entities::Entities(string n, int health, int dmg) : name(n), life(health), damage(dmg) {}

void Entities::printInfos() {
	cout << "Degats : " << damage << "Coordonnees : " << position.x << ", " << position.y << endl << endl;
}

void Entities::attack(Entities& target, int dmg) {
	damage = dmg;
	target.losePV(damage);
	cout << target.life << " PV" << endl << endl;
	cout << name << "lance une attaque sur " << target.name << " lui infligeant " << damage << " points de degats " << endl << endl;
}

int Entities::losePV(int damage) {
	life -= damage;
	if (life <= 0) {
		life = 0;
		isAlive = false;
	}
	return life;
}

int Entities::heal() {
	life += 30;
	return life;
}
int Entities::takeDamage(int pv) {
	life -= pv;
	return life;
}
int Entities::setLife(int pv) {
	life = pv;
	return life;
}

void Entities::update(float deltaTime) {
	sprite.setPosition(position);
}

void Entities::draw(RenderWindow& window) {
	window.draw(sprite);
}