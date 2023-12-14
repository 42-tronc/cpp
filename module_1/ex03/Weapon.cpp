#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

std::string const& Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string& type) {
    this->type = type;
}
