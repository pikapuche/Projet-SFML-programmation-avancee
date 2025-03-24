#include "stdafx.hpp"

class Entities {
public:

	string name;
	int damage;
	Vector2f position;
	int life;
	bool isAlive = true;

	bool SoundAttack = false;
	bool AttackMode = false;
	bool SoundHeal = false;
	bool SoundHit = false;
	bool printBody = false;
	bool readyToPlay = false;
	bool SoundAttack2 = false;

	int countAnimAtk = 0;
	int countAnimHeal = 0;
	int countAnimHit = 0;
	int countAnimDeath = 0;
	int DeathCount = 0;
	int countAnimAtk2 = 0;

	Texture texture;
	Sprite sprite;

	sf::Vector2i anim;
	sf::Vector2i anim_Attack;
	sf::Vector2i anim_Attack2;
	sf::Vector2i anim_Hit;
	sf::Vector2i anim_Death;

	enum State { IDLE, ATTACK, ATTACK2, DEAD, HEAL, HIT };
	State state;

	Entities(string n, int health, int dmg);

	void printInfos();

	void attack(Entities& target, int dmg);

	int losePV(int damage);

	int heal();

	int takeDamage(int pv);

	int setLife(int pv);

	void update(float deltaTime);

	void draw(RenderWindow& window);
};