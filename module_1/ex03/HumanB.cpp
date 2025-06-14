#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

void HumanB::attack() const {
    if (!weapon)
        std::cout << name << " has no weapon" << std::endl;
    else
        std::cout << name << " attacks with their " << weapon->getType()
                  << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}
