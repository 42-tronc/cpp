#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    std::cout << "\e[32m󰠓 Class created\e[;m" << std::endl;
    (void)filename;
    // checkFileContent("data.csv", true);
    // checkFileContent(filename);
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "\e[31m󰠓 Class destroyed\e[;m" << std::endl;
}

bool BitcoinExchange::isFileMissing(const std::string& filename) {
    std::ifstream file(filename.c_str());
    return !file.good();
}
