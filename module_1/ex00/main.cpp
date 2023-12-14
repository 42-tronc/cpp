#include "Zombie.hpp"

int main() {
    Zombie* zombax = newZombie("Theo");
    delete (zombax);

    randomChump("Michel");

    return 0;
}
