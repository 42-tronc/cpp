#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    ~WrongAnimal();

    WrongAnimal &operator=(const WrongAnimal &other);

    std::string getType() const;
    virtual void makeSound() const = 0;

private:
protected:
    std::string type;
};

#endif
