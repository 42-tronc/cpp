#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(const std::string& name) : name(name) {}

Zombie::~Zombie() {}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
