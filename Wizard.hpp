#include "Character.hpp"

class Wizard : public Character {
public:
	Wizard();
	void attack(Entities& target) override;
};