#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) {
    *this = other;
}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure& other) {
    if (this != &other) this->type = other.type;
    return *this;
}

AMateria* Cure::clone() const {
    return new Cure();
}

void Cure::use(ICharacter& target) {
    std::cout << "\e[32m* heals \e[3;37m" << target.getName()
              << "\e[;32m wounds *\e[0m" << std::endl;
}
