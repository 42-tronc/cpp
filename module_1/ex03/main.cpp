#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

void printAction(std::string str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main() {
    printAction("Giving a weapon to HumanA");
    {
        Weapon club = Weapon("crude spiked club");

        HumanA Michael("Michael", club);
        Michael.attack();
        club.setType("some other type of club");
        Michael.attack();
    }

    printAction("Giving a weapon to HumanB before attack");
    {
        Weapon club = Weapon("crude spiked club");

        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    printAction(
        "Giving no weapon to HumanB before attack and then giving a weapon");
    {
        Weapon club = Weapon("crude spiked club");

        HumanB Dwight("Dwight");
        Dwight.attack();
        Dwight.setWeapon(club);
        Dwight.attack();
        club.setType("some other type of club");
        Dwight.attack();
    }

    return 0;
}
