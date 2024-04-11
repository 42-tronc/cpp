
#include <iostream>
#include <vector>

#include "easyfind.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n" << std::endl;
}

int main(void) {
    printAction("This is a test");

    // std::vector<int> vect(1, 10);
    std::vector<int> vect(10, 10);
    // std::vector<std::string> words1{"the", "frogurt", "is", "also",
    // "cursed"};

    std::cout << "nums contains " << vect.size() << " elements.\n";

    return 0;
}
