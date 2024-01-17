#include "Cat.hpp"

Cat::Cat() : Animal() {
    type = "Cat";
    this->brain = new Brain();
    std::cout << "\e[32m󰄛 Cat\e[0m was born\n";
}

Cat::Cat(const Cat& other) : Animal() {
    std::cout << "\e[33m󰄛 Cat\e[0m copy constructor called\n";
    this->brain = new Brain();
    *this = other;
}

Cat::~Cat() {
    std::cout << "\e[31m󰄛 Cat\e[0m died\n";
    delete this->brain;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "\e[33m󰄛 Cat\e[0m assignation operator called\n";
    // Animal::operator=(other);
    this->type = other.type;
    *this->brain = *other.brain;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "\e[37m󰄛 Meow\e[0m\n";
}
