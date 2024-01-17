#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "\e[32mWrongCat\e[0m was born\n";
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << "\e[33mWrongCat\e[0m copy constructor called\n";
    *this = other;
}

WrongCat::~WrongCat() {
    std::cout << "\e[31mWrongCat\e[0m died\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "\e[33mWrongCat\e[0m assignation operator called\n";
    this->type = other.type;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "\e[37mWrong Meow\e[0m\n";
}
