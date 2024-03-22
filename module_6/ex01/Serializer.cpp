#include "Serializer.hpp"

Serializer::~Serializer() {
    std::cout << "Destructor called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    return *this;
}
