#include "Zombie.hpp"

int main() {
    Zombie* horde = zombieHorde(5, "Zombie");

    delete[] horde;
    return 0;
}
