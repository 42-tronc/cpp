#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "\e[32mWrongAnimal\e[0m was born\n";
    type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "\e[33mWrongAnimal\e[0m copy constructor called\n";
    *this = other;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "\e[31mWrongAnimal\e[0m died\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "\e[33mWrongAnimal\e[0m assignation operator called\n";
    type = other.type;
    return *this;
}

std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {
    std::cout << "\e[37mI am not even an animal, I don't make sounds\e[0m\n";
}
