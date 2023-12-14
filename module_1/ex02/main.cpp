#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Address of str: " << &str << std::endl
              << "Address held by stringPTR: " << stringPTR << std::endl
              << "Address held by stringREF: " << &stringREF << std::endl;

    std::cout << std::endl
              << "Value of str: " << str << std::endl
              << "Value pointed by stringPTR: " << *stringPTR << std::endl
              << "Value pointed by stringREF: " << stringREF << std::endl;

    return 0;
}
