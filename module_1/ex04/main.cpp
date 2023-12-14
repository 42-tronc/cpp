#include "Sed.hpp"

int main(int ac, char* av[]) {
    if (ac != 4) {
        printError("wrong number of arguments");
        std::cout << "\n\e[34mUsage: ./replace <filename> <s1> <s2>\e[0m" << std::endl;
        return 1;
    }
    Sed sed(av[1], av[2], av[3]);

    return 0;
}
