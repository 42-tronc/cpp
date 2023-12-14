#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
public:
    Zombie(std::string name); // Constructor
    Zombie(const Zombie& source); // Copy constructor (deep copy)
    ~Zombie();

    void announce();

private:
    std::string name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
