#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : name(name) {}

Zombie::Zombie(const Zombie& source) {
    this->name = source.name;
}

Zombie& Zombie::operator=(const Zombie& source) {
    this->name = source.name;
    return *this;
}

Zombie::~Zombie() {}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
