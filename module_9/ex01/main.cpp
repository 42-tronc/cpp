#include <iostream>

#include "RPN.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n" << std::endl;
}

int main(int ac, char* av[]) {
    try {
        if (ac != 2) {
            throw std::runtime_error("invalid number of arguments");
        }
        RPN rpn(av[1]);
    } catch (const std::exception& ex) {
        printError(ex.what());
        return 1;
    }

    return 0;
}
