#include <iostream>

#include "iter.hpp"

template <typename T>
void print(T &elem) {
    std::cout << elem << std::endl;
}

int main(void) {
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    std::string strArray[] = {"one", "two", "three", "four", "five"};

    std::cout << "Printing intArray:" << std::endl;
    iter(intArray, 5, print);

    std::cout << "\nPrinting charArray:" << std::endl;
    iter(charArray, 5, print);

    std::cout << "\nPrinting strArray:" << std::endl;
    iter(strArray, 5, print);

    return 0;
}
