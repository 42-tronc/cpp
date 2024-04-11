
#include <iostream>
#include <vector>

#include "easyfind.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n" << std::endl;
}

void tryFind(std::vector<int>& vect, int value) {
    try {
        std::vector<int>::iterator it = easyfind(vect, value);
        std::cout << "\e[32mValue found (" << *it << ") at index \e[1m"
                  << it - vect.begin() << "\e[0m" << std::endl;
    } catch (std::exception& ex) {
        std::cerr << "\e[31m" << ex.what() << "\e[0m" << std::endl;
    }
}

int main(void) {
    printAction("Create a vector with 4 elements of 100 and add 200 to it");
    std::vector<int> vect(4, 100);
    vect.push_back(200);
    for (size_t i = 0; i < vect.size(); i++) {
        std::cout << "vect[" << i << "] = " << vect[i] << std::endl;
    }
    std::cout << std::endl;

    printAction("Find 200 in the vector");
    tryFind(vect, 200);

    printAction("Find 300 in the vector");
    tryFind(vect, 300);

    printAction("Find 100 in the vector");
    tryFind(vect, 100);

    printAction("Find 0 in the vector");
    tryFind(vect, 0);

    return 0;
}
