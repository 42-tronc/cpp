#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap") {
    std::cout << "\e[32mFragTrap (\e[3;37m" << this->name
              << "\e[;32m) default constructor called\e[0m" << std::endl;
    this->hp = 100;
    this->maxHp = this->hp;
    this->energy = 100;
    this->dmg = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "\e[32mFragTrap (\e[3;37m" << this->name
              << "\e[;32m) constructor called\e[0m" << std::endl;
    this->hp = 100;
    this->maxHp = this->hp;
    this->energy = 100;
    this->dmg = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "\e[33mFragTrap (\e[3;37m" << other.getName()
              << "\e[;33m) copy constructor called\e[0m" << std::endl;
    *this = other;
}

FragTrap::~FragTrap() {
    std::cout << "\e[31mFragTrap (\e[3;37m" << this->name
              << "\e[;31m) destructor called\e[0m" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "\e[33mFragTrap (\e[3;37m" << other.getName()
              << "\e[;33m) assignation operator called\e[0m" << std::endl;
    this->name = other.name;
    this->dmg = other.dmg;
    this->energy = other.energy;
    this->hp = other.hp;
    return *this;
}

void FragTrap::highFivesGuys(void) {
    if (!checkAlive(*this)) return;
    std::string answer;
    std::cout << "\e[3;37m" << this->name << "\e[0m is requesting a "
              << "\e[1;35mHigh Five 󰹇\e[0m\n"
              << "Do you accept? (Y/n) ";
    getline(std::cin, answer);
    if (answer.compare("N") == 0 || answer.compare("n") == 0) {
        std::cout << "\e[3;37m" << this->name
                  << "\e[0m has been \e[1;31mdenied\e[0m a "
                  << "\e[1;35mHigh Five 󱩂\e[0m\n";
        std::cout << "\t\e[21;33mHow sad! 󱚝 \e[0m" << std::endl;
        return;
    }
    std::cout << "\e[3;37m" << this->name << "\e[0m has received a "
              << "\e[1;35mHigh Five 󱥋\e[0m\n";
    std::cout << "\t\e[21;33mMan he seems so happy! 󱜙 \e[0m" << std::endl;
}
