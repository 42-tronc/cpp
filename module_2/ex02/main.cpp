#include <iostream>

#include "Fixed.hpp"

void printAction(std::string str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main(void) {
    // Create two Fixed objects
    Fixed a(5);
    Fixed b(10);

    // Display the initial values
    printAction("Initial values");
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    // Assign b to a
    printAction("Assigning b to a");
    a = b;

    // Display the updated values
    printAction("Updated values");
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    // Test comparison operators
    printAction("Comparison operators");
    short columnWidth = 8;
    std::cout << std::boolalpha << std::setw(columnWidth)
              << "a > b: " << (a > b) << std::endl
              << std::setw(columnWidth) << "a < b: " << (a < b) << std::endl
              << std::setw(columnWidth) << "a >= b: " << (a >= b) << std::endl
              << std::setw(columnWidth) << "a <= b: " << (a <= b) << std::endl
              << std::setw(columnWidth) << "a == b: " << (a == b) << std::endl
              << std::setw(columnWidth) << "a != b: " << (a != b) << std::endl;

    // Test arithmetic operators
    printAction("Arithmetic operators");
    Fixed c = a + b;
    std::cout << "a + b = " << a + b << std::endl;
    Fixed d = a - b;
    std::cout << "a - b = " << d << std::endl;
    Fixed e = a * b;
    std::cout << "a * b = " << e << std::endl;
    Fixed f = a / b;
    std::cout << "a / b = " << f << std::endl;

    printAction("Increment and decrement operators");
    columnWidth = 4;
    std::cout << std::setw(columnWidth) << std::left << "a"
              << "= " << a << std::endl;
    std::cout << std::setw(columnWidth) << std::left << "++a"
              << "= " << ++a << std::endl;
    std::cout << std::setw(columnWidth) << std::left << "a"
              << "= " << a << std::endl;
    std::cout << std::setw(columnWidth) << std::left << "a++"
              << "= " << a++ << std::endl;
    std::cout << std::setw(columnWidth) << std::left << "a"
              << "= " << a << std::endl;
    std::cout << std::setw(columnWidth) << std::left << "--a"
              << "= " << --a << std::endl;
    std::cout << std::setw(columnWidth) << std::left << "a"
              << "= " << a << std::endl;
    std::cout << std::setw(columnWidth) << std::left << "a--"
              << "= " << a-- << std::endl;
    std::cout << std::setw(columnWidth) << std::left << "a"
              << "= " << a << std::endl;

    printAction("Min and max");
    std::cout << "\e[92mc\e[0m = " << c << std::endl
              << "\e[93md\e[0m = " << d << std::endl;

    std::cout << "min(\e[92mc\e[0m, \e[93md\e[0m): " << Fixed::min(c, d)
              << std::endl
              << "min(\e[92mc\e[0m, \e[92mc\e[0m): " << Fixed::min(c, c)
              << std::endl
              << "max(\e[92mc\e[0m, \e[93md\e[0m): " << Fixed::max(c, d)
              << std::endl
              << "max(\e[93md\e[0m, \e[93md\e[0m): " << Fixed::max(d, d)
              << std::endl;

    printAction("Min and max with const objects");
    const Fixed constE(e);
    const Fixed constF(f);
    std::cout << "\e[35mconstE\e[0m: " << constE << std::endl
              << "\e[36mconstF\e[0m: " << constF << std::endl
              << "min(\e[35mconstE\e[0m, \e[36mconstF\e[0m): "
              << Fixed::min(constE, constF) << std::endl
              << "min(\e[35mconstE\e[0m, \e[35mconstE\e[0m): "
              << Fixed::min(constE, constE) << std::endl
              << std::endl
              << "max(\e[35mconstE\e[0m, \e[36mconstF\e[0m): "
              << Fixed::max(constE, constF) << std::endl
              << "max(\e[36mconstF\e[0m, \e[36mconstF\e[0m): "
              << Fixed::max(constF, constF) << std::endl;

    printAction("Exiting the program");

    return 0;
}
