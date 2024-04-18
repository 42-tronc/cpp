#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstring>   // strlen
#include <ctime>     // time_t, localtime
#include <fstream>   // ifstream
#include <iostream>  // cout, cerr
#include <map>       // map
#include <sstream>   // istringstream

enum ErrorLevel { ERROR = 1, WARNING = 2 };

inline void printError(const std::string &message, short level,
    const std::string &details = "", bool usage = true) {
    std::string colour, prefix;
    if (level == ERROR) {
        colour = "\e[;31m";
        prefix = colour + "\e[1m[Error] " + colour;
    } else if (level == WARNING) {
        colour = "\e[;33m";
        prefix = colour + "\e[1m[Warning] " + colour;
    }

    std::cerr << prefix << message;
    if (!details.empty())
        std::cerr << " (\e[3;30m" << details << colour << ")";
    std::cerr << ".\e[0m" << std::endl;

    if (usage)
        std::cerr << "\n\e[1;33mUsage: \e[;33m./btc <file>\e[0m" << std::endl;
}

class BitcoinExchange {
public:
    BitcoinExchange(const std::string &filename);
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();

    BitcoinExchange &operator=(const BitcoinExchange &other);

    void processLine(const std::string &line, bool isDataCsv);

    void addEntry(const std::string &date, float exchangeRate);

private:
    BitcoinExchange();
    std::map<std::string, float> data;
    // std::string filename;
};

#endif
