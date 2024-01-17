#include "Ice.hpp"

Ice::Ice() {
    std::cout << "\e[21m\e[34mIce constructor\e[0m\n";
    this->type = "ice";
}

AMateria* Ice::clone() const {
    return new Ice();
}
