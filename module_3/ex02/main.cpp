#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main() {
    printAction(
        "Creating a FragTrap object, a ScavTrap object and a ClapTrap object");
    FragTrap john("John");
    ScavTrap rudolf("Rudolf");
    ClapTrap clapTrap("ClapTrap");

    printAction("Creating a copy of FragTrap object");
    FragTrap copyCat(john);

    printAction("Giving " + clapTrap.getName() + " 15 attack damage");
    clapTrap.setDmg(15);

    printAction("Make " + john.getName() + " attack " + rudolf.getName());
    std::cout << "\e[3;37m" << rudolf.getName() << "\e[0m has \e[1;32m"
              << rudolf.getHp() << "\e[0m HP" << std::endl;
    john.attack(rudolf.getName());
    rudolf.takeDamage(john.getDmg());

    printAction("Make Rudolf enter Gate keeper mode");
    rudolf.guardGate();

    printAction("Make John ask for a High Five");
    john.highFivesGuys();

    printAction("Make Rudolf quit Gate keeper mode and attack John");
    rudolf.guardGate();
    rudolf.attack(john.getName());
    john.takeDamage(rudolf.getDmg());

    printAction("Make John take his revenge");
    std::cout << "\e[3;37m" << rudolf.getName() << "\e[0m has \e[1;32m"
              << rudolf.getHp() << "\e[0m HP" << std::endl;
    for (int i = 0; i < 5; i++) {
        john.attack(rudolf.getName());
        rudolf.takeDamage(john.getDmg());
    }

    printAction("Exiting the program");

    return 0;
}
