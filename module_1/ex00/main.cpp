#include "Zombie.hpp"

int main() {
    Zombie* zombax = newZombie("Theo");
    zombax->announce();
    delete (zombax);

    randomChump("Michel");

    return 0;
}
