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

    ::swap(a, b);
    std::cout << "a = " << a << std::setw(8) << "b = " << b << std::endl;

    printAction("Use min function to find the smallest value");
    std::cout << "min(" << a << ", " << b << ") = " << ::min(a, b) << std::endl;

    printAction("Use max function to find the biggest value");
    std::cout << "max(" << a << ", " << b << ") = " << ::max(a, b) << std::endl;

    printAction("Define two double variables and swap them");
    double c = 2.5;
    double d = 9.5;
    std::cout << "c = " << c << std::setw(8) << "d = " << d << std::endl;

    ::swap(c, d);
    std::cout << "c = " << c << std::setw(8) << "d = " << d << std::endl;

    printAction("Use min function to find the smallest value");
    std::cout << "min(" << c << ", " << d << ") = " << ::min(c, d) << std::endl;

    printAction("Use max function to find the biggest value");
    std::cout << "max(" << c << ", " << d << ") = " << ::max(c, d) << std::endl;

    printAction("Define two strings and swap them");
    std::string e = "chaine1";
    std::string f = "chaine2";
    std::cout << "e = " << e << std::setw(8) << "f = " << f << std::endl;

    ::swap(e, f);
    std::cout << "e = " << e << std::setw(8) << "f = " << f << std::endl;

    printAction("Use min function to find the smallest value");
    std::cout << "min(" << e << ", " << f << ") = " << ::min(e, f) << std::endl;

    printAction("Use max function to find the biggest value");
    std::cout << "max(" << e << ", " << f << ") = " << ::max(e, f) << std::endl;

    return 0;
}
