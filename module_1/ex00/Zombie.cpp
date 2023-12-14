#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

Zombie::Zombie(const Zombie& source) {
    this->name = source.name;
}

Zombie::~Zombie() {}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
