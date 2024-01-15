#include "ScavTrap.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main() {
    printAction("Creating 2 ScavTrap objects and 2 ClapTrap object");
    ScavTrap john("John");
    ScavTrap rudolf("Rudolf");
    ClapTrap clapTrap("Clapi");
    ClapTrap clapTrap2;

    printAction("Creating a copy of ScavTrap object");
    ScavTrap copyCat(john);

    printAction("Giving " + clapTrap.getName() + " 15 attack damage");
    clapTrap.setDmg(15);

    printAction("Make " + john.getName() + " attack " + rudolf.getName());
    john.attack(rudolf.getName());
    rudolf.takeDamage(john.getDmg());

    printAction("Clapi attacks " + rudolf.getName());
    for (int i = 0; i < 6; i++) {
        clapTrap.attack(rudolf.getName());
        rudolf.takeDamage(clapTrap.getDmg());
    }

    printAction("Make everyone guard the gate");
    rudolf.guardGate();
    // clapTrap.guardGate();
    john.guardGate();

    printAction("Make " + john.getName() + " no longer guard the gate");
    john.guardGate();

    printAction("Exiting the program");

    return 0;
}
