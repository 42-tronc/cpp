#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
public:
    Zombie();
    Zombie(const std::string& name);
    Zombie(const Zombie& source);
    Zombie& operator=(const Zombie& source);
    ~Zombie();

    void announce();

private:
    std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
