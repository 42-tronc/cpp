#include <iostream>

#include "Fixed.hpp"

void printAction(std::string str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main(void) {
    printAction("a with default constructor");
    Fixed a;
    printAction("b with int constructor");
    Fixed const b(10);
    printAction("c with float constructor");
    Fixed const c(42.42f);
    printAction("d with copy constructor");
    Fixed const d(b);

    printAction("a with assignation operator");
    a = Fixed(1234.4321f);

    printAction("Float values");
    std::cout << "a is " << a << std::endl
              << "b is " << b << std::endl
              << "c is " << c << std::endl
              << "d is " << d << std::endl;

    printAction("Integer values");
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    printAction("Exiting the program");

    return 0;
}
