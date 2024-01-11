#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
    Animal();
    Animal(const Animal &src);
    virtual ~Animal();  // to make it polymorphic

    Animal &operator=(const Animal &src);

    std::string getType() const;
    virtual void makeSound() const;

private:
protected:
    std::string type;
};

#endif
