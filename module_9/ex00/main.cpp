#include "BitcoinExchange.hpp"

void checkFileExist(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.good()) {
        throw std::runtime_error(filename + " is missing");
    }
}

int main(int ac, char** av) {
    if (ac != 2 || !strlen(av[1])) {
        printError("invalid number of arguments", ERROR);
        return 1;
    }

    try {
        checkFileExist("data.csv");
        checkFileExist(av[1]);

        BitcoinExchange btc(av[1]);
        // checkFileContent("data.csv", true);
        // checkFileContent(av[1]);

    } catch (const std::exception& ex) {
        printError(ex.what(), ERROR);
        return 1;
    }
    std::cout << "\n\e[1;32mSuccess: \e[;32mboth files are valid.\e[0m"
              << std::endl;

    return 0;
}
