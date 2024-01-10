#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ~ClapTrap();

    ClapTrap& operator=(ClapTrap const& other);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    bool checkAlive(ClapTrap& player);
    bool checkEnergy(ClapTrap& player);

    std::string getName() const;
    unsigned int getDmg() const;
    unsigned int getHp() const;
    unsigned int getEnergy() const;
    void setDmg(unsigned int dmg);

protected:
    std::string name;
    unsigned int hp;
    unsigned int maxHp;
    unsigned int energy;
    unsigned int dmg;
};

#endif
