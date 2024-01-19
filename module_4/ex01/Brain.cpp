#include "Brain.hpp"

#include <iostream>
#include <string>

Brain::Brain() {
    std::cout << "\e[32m󰧑 Brain\e[0m constructor called\n";
}

Brain::Brain(const Brain& other) {
    std::cout << "\e[33m󰧑 Brain\e[0m copy constructor called\n";
    *this = other;
}

Brain::~Brain() {
    std::cout << "\e[31m󰧑 Brain\e[0m destructor called\n";
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "\e[33m󰧑 Brain\e[0m assignation operator called\n";
    for (int i = 0; i < 100; i++) ideas[i] = other.ideas[i];
    return *this;
}
