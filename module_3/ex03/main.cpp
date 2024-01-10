#include "DiamondTrap.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main() {
    printAction(
        "Creating a FragTrap object, a ScavTrap object and a ClapTrap object");
    ClapTrap clapTrap("ClapTrap");
    DiamondTrap diamondTrap("DiamondTrap");

    printAction("Creating a copy of DiamondTrap");
    DiamondTrap diamondTrapCopy(diamondTrap);

    // HP (100) from FragTrap
    // Energy (50) from ScavTrap
    // Damage (30) from FragTrap

    printAction(
        "Making " + diamondTrap.getName() + " attack " + clapTrap.getName());
    diamondTrap.attack(clapTrap.getName());
    clapTrap.takeDamage(diamondTrap.getDmg());

    printAction("Run whoAmI() on " + diamondTrap.getName());
    diamondTrap.whoAmI();

    printAction("Create a FragTrap object");
    FragTrap fragTrap("FragTrap");

    printAction("Make " + diamondTrap.getName() + " be repaired");
    diamondTrap.beRepaired(10);
    diamondTrap.guardGate();

    // printAction(
    //     "Make " + fragTrap.getName() + " attack " + diamondTrap.getName());
    // for (int i = 0; i < 6; i++) {
    //     fragTrap.attack(diamondTrap.getName());
    //     diamondTrap.takeDamage(fragTrap.getDmg());
    // }

    printAction("Exiting the program");

    return 0;
}
