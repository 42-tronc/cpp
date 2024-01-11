#include "ClapTrap.hpp"

void printAction(std::string str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main() {
    printAction("Create two ClapTrap objects");
    ClapTrap thomas("Thomas Jefferson");
    ClapTrap george("George Washington");

    printAction("Create a ClapTrap object using the copy constructor");
    ClapTrap thomasCopy(thomas);

    printAction("Make Thomas Jefferson attack a dummy target");
    thomas.attack("a dummy target");

    printAction("Give Thomas Jefferson an attack damage of 5");
    thomas.setDmg(5);

    printAction("Make Thomas Jefferson attack a dummy target");
    thomas.attack("a dummy target");

    printAction("Make Thomas Jefferson attack George Washington");
    thomas.attack(george.getName());
    george.takeDamage(thomas.getDmg());
    george.beRepaired(thomas.getDmg() / 2);

    printAction("Overhealing Thomas Jefferson");
    std::cout << "Thomas Jefferson has " << thomas.getHp() << " hit points"
              << std::endl;
    thomas.beRepaired(10);

    printAction("Repair George back to full health");
    george.beRepaired(10 - george.getHp());

    printAction("Give George Washington an attack damage of 15");
    george.setDmg(15);

    printAction("Make George Washington finally take down Thomas Jefferson");
    george.attack(thomas.getName());
    thomas.takeDamage(george.getDmg());

    printAction(
        "Make George Washington attack the already dead Thomas Jefferson");
    george.attack(thomas.getName());
    thomas.takeDamage(george.getDmg());

    printAction("Make George Washington attack damage 1");
    george.setDmg(1);

    printAction("Make George Washington chain attack dummy targets");
    for (int i = 0; i < 9; i++) {
        george.attack("a dummy target");
        // george.takeDamage(george.getDmg());
    }

    printAction("Exiting the program");

    return 0;
}
