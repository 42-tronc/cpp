#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
    Animal();
    Animal(const Animal &other);
    virtual ~Animal();  // to make it polymorphic

    Animal &operator=(const Animal &other);

    std::string getType() const;
    virtual void makeSound() const = 0;

protected:
    std::string type;
};

#endif
