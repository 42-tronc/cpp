#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
    std::cout << "\e[32mScavTrap (\e[3;37m" << this->name
              << "\e[;32m) default constructor called\e[0m" << std::endl;
    this->guarding = 0;
    this->hp = 100;
    this->maxHp = this->hp;
    this->energy = 50;
    this->dmg = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "\e[32mScavTrap (\e[3;37m" << this->name
              << "\e[;32m) constructor called\e[0m" << std::endl;
    this->guarding = 0;
    this->hp = 100;
    this->maxHp = this->hp;
    this->energy = 50;
    this->dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "\e[33mScavTrap (\e[3;37m" << other.getName()
              << "\e[;33m) copy constructor called\e[0m" << std::endl;
    // this->name = other.name;
    // this->hp = other.hp;
    // this->energy = other.energy;
    // this->dmg = other.dmg;
    *this = other;
}

ScavTrap::~ScavTrap() {
    std::cout << "\e[31mScavTrap (\e[3;37m" << this->name
              << "\e[;31m) destructor called\e[0m" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "\e[33mScavTrap (\e[3;37m" << other.getName()
              << "\e[;33m) assignation operator called\e[0m" << std::endl;
    this->name = other.name;
    this->hp = other.hp;
    this->energy = other.energy;
    this->dmg = other.dmg;
    this->guarding = other.guarding;
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (!checkAlive(*this) || !checkEnergy(*this)) return;
    std::cout << "ScavTrap \e[3;37m" << this->name
              << " \e[;1;91mattacks\e[;3;37m " << target
              << "\e[0m, causing \e[1;31m" << this->dmg
              << "\e[m points of damage!\e[0m" << std::endl;
    if (this->dmg == 0)
        std::cout << "\t\e[21;33mWow! that's embarrassing!\e[0m" << std::endl;
    this->getEnergy();
}

void ScavTrap::guardGate() {
    if (!checkAlive(*this)) return;
    std::string guardStatus;
    if (guarding)
        guardStatus = "no longer";
    else
        guardStatus = "now";
    guarding = !guarding;
    std::cout << "\e[3;37m" << this->name << "\e[0m is " << guardStatus
              << " in \e[1;36mGate Keeping 󱢾\e[0m mode" << std::endl;
}
