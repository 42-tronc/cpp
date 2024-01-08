#include "Zombie.hpp"

std::string printAction(std::string str) {
    return "\n\e[1;33m* \e[21m\e[34m" + str + "\e[0m\n\n";
}

int main() {
    std::cout << printAction("Zombie on the stack");
    Zombie* zombax = newZombie("Theo");
    zombax->announce();
    delete (zombax);

    std::cout << printAction("Zombie on the heap");
    randomChump("Michel");

    return 0;
}
