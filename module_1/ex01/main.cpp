#include "Zombie.hpp"

int main() {
    short zombiesCount = 5;
    std::cout << "\e[1;33m* \e[21m\e[34mCreating " << zombiesCount
              << " zombies\e[0m\n\n";
    Zombie* horde = zombieHorde(zombiesCount, "Zombie");

    delete[] horde;
    return 0;
}
