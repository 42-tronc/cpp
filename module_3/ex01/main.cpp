#include "ScavTrap.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main() {
    printAction("Creating 2 ScavTrap objects and 1 ClapTrap object");
    ScavTrap john("John");
    ScavTrap rudolf("Rudolf");
    ClapTrap clapTrap("ClapTrap");

    printAction("Creating a copy of ScavTrap object");
    ScavTrap copyCat(john);

    printAction("Giving ClapTrap 15 attack damage");
    clapTrap.setDmg(15);

    printAction("Make John attack ScavTrap2");
    john.attack(rudolf.getName());
    rudolf.takeDamage(john.getDmg());

    printAction("Exiting the program");

    return 0;
}
