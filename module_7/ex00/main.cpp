#include <iomanip>
#include <iostream>

#include "whatever.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main(void) {
    printAction("Define two variables and swap them");
    int a = 2;
    int b = 3;
    std::cout << "a = " << a << std::setw(8) << "b = " << b << std::endl;

    swap(a, b);
    std::cout << "a = " << a << std::setw(8) << "b = " << b << std::endl;

    return 0;
}
