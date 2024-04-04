#include <iostream>

#include "iter.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

template <typename T>
void print(const T& elem) {
    std::cout << elem << std::endl;
}

int main(void) {
    printAction("Creating arrays");
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    std::string strArray[] = {"one", "two", "three", "four", "five"};

    printAction("Printing arrays");
    iter(intArray, 5, print);

    printAction("Printing charArray");
    iter(charArray, 5, print);

    printAction("Printing strArray");
    iter(strArray, 5, print);

    printAction("Create const arrays");
    const int intArrayConst[] = {1, 2, 3, 4, 5};

    std::cout << "Printing intArrayConst:" << std::endl;
    iter(intArrayConst, 5, print);

    return 0;
}
