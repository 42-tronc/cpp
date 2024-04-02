#include <stdlib.h>

#include <iostream>

#include "Base.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

Base* generate(void) {
    srand(time(NULL));
    int random = rand() % 3;

    std::cout << "\e[1mNumber generated: \e[34m" << random << "\e[0m"
              << std::endl;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    std::cout << "\e[1mIdentifying pointer: \e[34m";
    if (dynamic_cast<A*>(p))
        std::cout << "A";
    else if (dynamic_cast<B*>(p))
        std::cout << "B";
    else if (dynamic_cast<C*>(p))
        std::cout << "C";
    std::cout << "\e[0m" << std::endl;
}

void identify(Base& p) {
    std::cout << "\e[1mIdentifying reference: \e[34m";
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A";
    } catch (std::exception& e) {
        try {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B";
        } catch (std::exception& e) {
            try {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C";
            } catch (std::exception& e) {
                std::cout << "Unknown";
            }
        }
    }
    std::cout << "\e[0m" << std::endl;
}

int main(void) {
    printAction("Generating random class");
    Base* base = generate();

    printAction("Identifying class by pointer");
    identify(base);

    printAction("Identifying class by reference");
    identify(*base);

    delete base;

    return 0;
}
