#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
public:
    Zombie(const std::string& name); // Constructor
    Zombie(const Zombie& source); // Copy constructor
    Zombie& operator=(const Zombie& source); // Copy assignment operator
    ~Zombie();

    void announce();

private:
    std::string name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
