#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "\e[32mAnimal\e[0m was born\n";
}

Animal::Animal(const Animal& other) {
    std::cout << "\e[33mAnimal\e[0m copy constructor called\n";
    *this = other;
}

Animal::~Animal() {
    std::cout << "\e[31mAnimal\e[0m died\n";
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "\e[33mAnimal\e[0m assignation operator called\n";
    type = other.type;
    return *this;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout
        << "\e[37mWhat exactly do you want me to say? Quack? I am not a "
           "duck or any specific animal for that matter sir. I don't "
           "understand what you want from me! Please leave me alone.\e[0m\n";
}
