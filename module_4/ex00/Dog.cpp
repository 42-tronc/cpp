#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "\e[32m󰩃 Dog\e[0m was born\n";
    type = "Dog";
}

Dog::Dog(const Dog& other) : Animal() {
    std::cout << "\e[33m󰩃 Dog\e[0m copy constructor called\n";
    *this = other;
}

Dog::~Dog() {
    std::cout << "\e[31m󰩃 Dog\e[0m died\n";
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "\e[33m󰩃 Dog\e[0m assignation operator called\n";
    type = other.type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "\e[37m󰩃 Woof\e[0m\n";
}
