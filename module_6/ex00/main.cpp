#include <cstring>

#include "ScalarConverter.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main(int ac, char** av) {
    std::cout << "\e[;37m";

    if (ac != 2 || !strlen(av[1])) {
        std::cerr
            << "\e[1;31mError: \e[;31mInvalid number of arguments.\e[0m\n\n"
            << "\e[33mUsage: ./scalar_converter <value>\e[0m" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);

    return 0;
}
