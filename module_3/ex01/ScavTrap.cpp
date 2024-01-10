#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "\e[32mScavTrap (" << this->name << ") constructor called\e[0m"
              << std::endl;
    this->hp = 100;
    this->energy = 50;
    this->dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "\e[33mScavTrap (" << this->name
              << ") copy constructor called\e[0m" << std::endl;
    // this->name = other.name;
    // this->hp = other.hp;
    // this->energy = other.energy;
    // this->dmg = other.dmg;
    *this = other;
}

ScavTrap::~ScavTrap() {
    std::cout << "\e[31mScavTrap (" << this->name << ") destructor called\e[0m"
              << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& other) {
    std::cout << "\e[33mScavTrap (" << this->name
              << ") assignation operator called\e[0m" << std::endl;
    this->name = other.name;
    this->hp = other.hp;
    this->energy = other.energy;
    this->dmg = other.dmg;
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
    std::cout << "\e[1;33mScavTrap (" << this->name
              << ") has entered in \e[1;31mGate Keeper 󰒘\e[1;33m mode\e[0m"
              << std::endl;
}
