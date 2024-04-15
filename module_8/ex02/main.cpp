#include "MutantStack.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n" << std::endl;
}

int main(void) {
    printAction("Create a default MutantStack");
    MutantStack<int> mstack;

    printAction("Print the size of the MutantStack");
    std::cout << mstack.size() << std::endl;

    printAction("Push 5 and 17 to the MutantStack and print the top");
    mstack.push(5);
    mstack.push(17);
    std::cout << "\e[33m󰘣 Top: \e[1m" << mstack.top() << "\e[0m"
              << std::endl;

    printAction("Print the size of the MutantStack before popping");
    std::cout << "\e[33m󰡏 Size: \e[1m" << mstack.size() << "\e[0m"
              << std::endl;


    // printAction("Pop the MutantStack and print the size");
    // mstack.pop();
    // std::cout << mstack.size() << std::endl;

    // printAction("Push 3, 5, and 737 to the MutantStack");
    // mstack.push(3);
    // mstack.push(5);
    // mstack.push(737);
    // //[...]
    // mstack.push(0);

    // printAction("Iterate through the MutantStack and print the values");
    // MutantStack<int>::iterator it = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    // while (it != ite) {
    //     std::cout << *it << std::endl;
    //     ++it;
    // }
    // std::stack<int> s(mstack);

    return 0;
}
