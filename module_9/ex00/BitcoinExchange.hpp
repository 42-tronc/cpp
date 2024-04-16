#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

class BitcoinExchange {
public:
    ~BitcoinExchange();
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);

    BitcoinExchange &operator=(const BitcoinExchange &other);

    static bool isFileMissing(const std::string &filename);

private:
    std::map<std::string, float> data;
    // std::string filename;
};

#endif
