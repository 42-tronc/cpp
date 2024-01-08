#include <iostream>

#include "Fixed.hpp"

void printAction(std::string str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main(void) {
    printAction("Creating `a` with the default constructor");
    Fixed a;
    a.setRawBits(21);

    printAction("Creating `b` with the assignation operator");
    Fixed b;
    b = a;

    printAction("Creating `c` with the copy constructor");
    Fixed c(a);

    printAction("Printing the values of `a`, `b` and `c`");
    std::cout << "a = " << a.getRawBits() << std::endl
              << "b = " << b.getRawBits() << std::endl
              << "c = " << c.getRawBits() << std::endl;

    printAction("Changing the value of `a`");
    a.setRawBits(69);
    std::cout << "a = " << a.getRawBits() << std::endl
              << "b = " << b.getRawBits() << std::endl
              << "c = " << c.getRawBits() << std::endl;

    printAction("Changing the value of `c`");
    c.setRawBits(42);
    std::cout << "c = " << c.getRawBits() << std::endl;

    printAction("Exiting the program");

    return 0;
}
