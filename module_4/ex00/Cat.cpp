#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "\e[32m󰄛 Cat\e[0m was born\n";
    type = "Cat";
}

Cat::Cat(const Cat& other) : Animal() {
    std::cout << "\e[33m󰄛 Cat\e[0m copy constructor called\n";
    *this = other;
}

Cat::~Cat() {
    std::cout << "\e[31m󰄛 Cat\e[0m died\n";
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "\e[33m󰄛 Cat\e[0m assignation operator called\n";
    type = other.type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "\e[37m󰄛 Meow\e[0m\n";
}
