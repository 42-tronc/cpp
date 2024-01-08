#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
public:
    Zombie(const std::string& name);
    ~Zombie();

    void announce();

private:
    std::string name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
