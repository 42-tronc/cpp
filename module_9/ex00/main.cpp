#include <cstring>
#include <iomanip>
#include <iostream>

#include "BitcoinExchange.hpp"

// enum for the error level
enum ErrorLevel { ERROR = 1, WARNING = 2 };

void printError(const std::string& message, short level,
    const std::string& details = "", bool usage = true) {
    std::string colour, prefix;
    if (level == ERROR) {
        colour = "\e[;31m";
        prefix = "\e[1;31mError: " + colour;
    } else if (level == WARNING) {
        colour = "\e[;33m";
        prefix = "\e[1;33mWarning: \e[;33m";
    }

    std::cerr << prefix << message;
    if (!details.empty())
        std::cerr << " (\e[3;30m" << details << colour << ")";
    std::cerr << ".\e[0m" << std::endl;

    if (usage)
        std::cerr << "\n\e[1;33mUsage: \e[;33m./btc <file>\e[0m" << std::endl;
}

void checkFileExist(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.good()) {
        throw std::runtime_error(filename + " is missing");
    }
}

bool checkFileHeader(bool isDataCsv, std::string& line) {
    if (isDataCsv && line == "date,exchange_rate")
        return true;
    else if (!isDataCsv && line == "date | value")
        return true;
    else
        throw std::runtime_error("invalid header");

    return false;
}

bool checkFileDelimiter(bool isDataCsv, std::string& delim) {
    if (isDataCsv && delim == ",")
        return true;
    else if (!isDataCsv && delim == "|")
        return true;
    else
        throw std::runtime_error("invalid delimiter");

    return false;
}

void checkFileContent(const std::string& filename, bool isDataCsv = false) {
    std::ifstream file(filename.c_str());
    std::string line;
    bool isFirstLine = true;

    // Check if the file is empty
    if (file.peek() == std::ifstream::traits_type::eof() || !file.good())
        throw std::runtime_error(filename + " is empty");

    while (std::getline(file, line)) {
        // Check the first line
        if (isFirstLine && checkFileHeader(isDataCsv, line)) {
            isFirstLine = false;
            continue;
        }

        std::istringstream iss(line);
        std::string date, delimiter, valueStr;
        float value = 0;

        if (isDataCsv) {
            std::getline(iss, date, ',');
            std::getline(iss, valueStr);
            std::istringstream issValue(valueStr);
            issValue >> value;
            delimiter = line.at(10);
        } else
            iss >> date >> delimiter >> value;

        // std::cout << "\e[1mDate: \e[;35m" << std::setw(10) << date
        //           << "\e[0m | \e[1mValue: \e[;35m" << std::setw(3) <<
        //           valueStr
        //           << "\e[0m iss: \e[31m" << iss.fail()
        //           << "\e[0m delimiter: `\e[31m" << delimiter << "\e[0m`"
        //           << std::endl;

        if (iss.fail() || !checkFileDelimiter(isDataCsv, delimiter) ||
            date.empty()) {
            printError("Your error message here", ERROR, false);
            // printError("invalid file format", WARNING, line, false);
        }
    }
}

int main(int ac, char** av) {
    if (ac != 2 || !strlen(av[1])) {
        printError("invalid number of arguments.", ERROR);
        return 1;
    }

    try {
        checkFileExist(av[1]);
        checkFileExist("data.csv");
        checkFileContent(av[1]);
        std::cout << "\e[1;32mSuccess: \e[;32m" << av[1] << " is valid.\e[0m"
                  << std::endl;
        checkFileContent("data.csv", true);
        std::cout << "\e[1;32mSuccess: \e[;32mdata.csv is valid.\e[0m"
                  << std::endl;

    } catch (const std::exception& ex) {
        printError(ex.what(), ERROR);
    }

    return 0;
}

// TODO:
// [x] data.csv should be here
// [x] must take a file as an arg
// [x] date | value for input
// [x] date,value for data.csv
// [] YYYY-MM-DD | value
// [] value is a float between 0 and 1000
// [] date is not before 2009-01-09 (bitcoin creation date)
// [] date is not after the current date
