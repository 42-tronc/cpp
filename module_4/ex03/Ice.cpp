#include "Ice.hpp"

Ice::Ice() {
    this->type = "ice";
}

Ice::Ice(const Ice& other) {
    *this = other;
}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& other) {
    if (this != &other) this->type = other.type;
    return *this;
}

AMateria* Ice::clone() const {
    return new Ice();
}

void Ice::use(ICharacter& target) {
    std::cout << "\e[36m* shoots an ice bolt at \e[3;37m" << target.getName()
              << "\e[0;36m *\e[0m" << std::endl;
}
