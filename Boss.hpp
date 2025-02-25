#include "Enemy.hpp"

class Boss : public Enemy {
public:
	Boss();
	void attack(Entities& target) override;
};