#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
    this->name = "DiamondTrap";
    this->hp = FragTrap::hp;
    this->maxHp = this->hp;
    this->energy = ScavTrap::energy;
    this->dmg = 30;  // FragTrap::dmg;
    std::cout << "\e[32mDiamondTrap (\e[3;37m" << this->name
              << "\e[;32m) constructor called\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
    std::cout << "\e[32mDiamondTrap (\e[3;37m" << name
              << "\e[;32m) constructor called\e[0m" << std::endl;
    this->name = name;
    this->hp = FragTrap::hp;
    this->maxHp = this->hp;
    this->energy = ScavTrap::energy;
    this->dmg = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    *this = other;
    std::cout << "\e[33mDiamondTrap (\e[3;37m" << name
              << "\e[;33m) copy constructor called\e[0m" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "\e[31mDiamondTrap (\e[3;37m" << this->name
              << "\e[;31m) destructor called\e[0m" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    this->name = other.name;
    this->hp = other.hp;
    this->maxHp = other.maxHp;
    this->energy = other.energy;
    this->dmg = other.dmg;
    std::cout << "\e[33mDiamondTrap (\e[3;37m" << name
              << "\e[;33m) assignation operator called\e[0m" << std::endl;
    return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << "\e[3;37m" << this->name << "\e[0m is "
              << "\e[1;35m" << this->ClapTrap::name << "\e[0m" << std::endl;
}
