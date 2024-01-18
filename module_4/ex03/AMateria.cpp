#include "AMateria.hpp"

AMateria::AMateria() : type("AMateria") {}

AMateria::AMateria(const std::string& type) : type(type) {}

AMateria::AMateria(const AMateria& other) {
    *this = other;
}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) this->type = other.type;
    return *this;
}

std::string const& AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "Impossible to use AMateria directly" << std::endl;
}
