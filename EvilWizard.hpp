#include "Enemy.hpp"

class EvilWizard : public Enemy {
public:
	EvilWizard();
	void attack(Entities& target) override;
};