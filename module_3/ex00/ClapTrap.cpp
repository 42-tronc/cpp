#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("ClapTrap"), hp(10), energy(10), dmg(0) {
    this->maxHp = this->hp;
    std::cout << "\e[32mClapTrap (\e[3;37m" << this->name
              << "\e[;32m) default constructor called\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), energy(10), dmg(0) {
    this->maxHp = this->hp;
    std::cout << "\e[32mClapTrap (\e[3;37m" << this->name
              << "\e[;32m) constructor called\e[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "\e[33mClapTrap (\e[3;37m" << other.getName()
              << "\e[;33m) copy constructor called\e[0m" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap() {
    std::cout << "\e[31mClapTrap (\e[3;37m" << this->name
              << "\e[;31m) destructor called\e[0m" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& other) {
    std::cout << "\e[33mClapTrap (\e[3;37m" << other.getName()
              << "\e[;33m) assignation operator called\e[0m" << std::endl;
    this->name = other.name;
    this->hp = other.hp;
    this->maxHp = this->hp;
    this->energy = other.energy;
    this->dmg = other.dmg;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (!checkAlive(*this) || !checkEnergy(*this)) return;
    std::cout << "ClapTrap \e[3;37m" << this->name
              << " \e[;1;91mattacks\e[;3;37m " << target
              << "\e[0m, causing \e[1;31m" << this->dmg
              << "\e[m points of damage!\e[0m" << std::endl;
    if (this->dmg == 0)
        std::cout << "\t\e[21;33mWow! that's embarrassing!\e[0m" << std::endl;
    this->getEnergy();
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (!checkAlive(*this)) return;
    std::string damageStatus;
    if (amount >= this->hp) {
        amount = this->hp;
        damageStatus = "killed";
    } else
        damageStatus = "damaged";
    this->hp -= amount;
    std::cout << "\e[3;37m" << this->name << " \e[;1;91mhas been "
              << damageStatus << "\e[0m, losing \e[1;31m" << amount
              << " 󰓥\e[m hit points! (\e[1;31m" << this->hp << "HP\e[m)"
              << std::endl;
    if (this->hp == 0)
        std::cout << "\t\e[21;33m󰚌 May you rest in peace. 󰚌 \e[0m"
                  << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!checkAlive(*this) || !checkEnergy(*this)) return;
    std::string repairStatus;
    if (amount + this->hp >= this->maxHp) {
        repairStatus = "fully repaired";
        amount = this->maxHp - this->hp;
    } else
        repairStatus = "repaired";
    this->hp += amount;
    std::cout << "ClapTrap \e[3;37m" << this->name << " \e[;1;92mhas been "
              << repairStatus << "\e[0m, gaining \e[1;32m" << amount
              << "\e[m hit points! (\e[1;32m" << this->hp << "HP\e[m)"
              << std::endl;
    this->getEnergy();
}

bool ClapTrap::checkAlive(ClapTrap& player) {
    if (player.hp <= 0) {
        std::cout << "\e[3;37m" << player.name
                  << "\e[m is already \e[1;31mdead 󰚌 !\e[0m" << std::endl;
        std::cout << "\t\e[21;33mSomeone stop this man!\e[0m" << std::endl;
        return false;
    }
    return true;
}

bool ClapTrap::checkEnergy(ClapTrap& player) {
    if (player.energy <= 0) {
        std::cout << "\e[3;37m" << player.name
                  << " is out of \e[1;33menergy !\e[0m" << std::endl;
        return false;
    } else
        player.energy--;

    return true;
}

std::string ClapTrap::getName() const {
    return this->name;
}

// Getters
unsigned int ClapTrap::getDmg() const {
    return this->dmg;
}

unsigned int ClapTrap::getHp() const {
    return this->hp;
}

unsigned int ClapTrap::getEnergy() const {
    std::cout << "\t\e[90m " << this->name << " has " << this->energy
              << " energy left!\e[0m" << std::endl;
    return this->energy;
}

// Setters
void ClapTrap::setDmg(unsigned int dmg) {
    this->dmg = dmg;
    std::cout << "\e[3;37m" << this->name << "\e[m now has \e[1;31m" << dmg
              << " 󰓥 attack damage\e[0m" << std::endl;
}
