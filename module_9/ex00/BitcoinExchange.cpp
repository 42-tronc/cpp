#include "BitcoinExchange.hpp"

bool BitcoinExchange::isFileMissing(const std::string& filename) {
    std::ifstream file(filename.c_str());
    return !file.good();
}
