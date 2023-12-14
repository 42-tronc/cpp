#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA {
public:
    HumanA(std::string name, Weapon& weapon);

    void attack() const;

private:
    std::string name;
    Weapon& weapon;
};

#endif
