#include <cstring>
#include <iomanip>
#include <iostream>

#include "BitcoinExchange.hpp"

void printError(const std::string& message, bool usage = true) {
    std::cerr << "\e[1;31mError: \e[;31m" << message << "\e[0m" << std::endl;
    if (usage)
        std::cerr << "\n\e[1;33mUsage: \e[;33m./btc <file>\e[0m" << std::endl;
}

void checkFileExist(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.good()) {
        throw std::runtime_error(filename + " is missing.");
    }
}

bool checkFileHeader(bool isDataCsv, std::string& line) {
    if (isDataCsv && line == "date,exchange_rate")
        return true;
    else if (!isDataCsv && line == "date | value")
        return true;
    else
        throw std::runtime_error("invalid header (" + line + ").");

    return false;
}

bool checkFileDelimiter(bool isDataCsv, std::string& delim) {
    if (isDataCsv && delim == ",")
        return true;
    else if (!isDataCsv && delim == "|")
        return true;
    else
        throw std::runtime_error("invalid header delimiter (" + delim + ").");

    return false;
}

void checkFileContent(const std::string& filename, bool isDataCsv = false) {
    std::ifstream file(filename.c_str());
    std::string line;
    bool isFirstLine = true;

    // Check if the file is empty
    if (file.peek() == std::ifstream::traits_type::eof() || !file.good())
        throw std::runtime_error(filename + " is empty.");

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

        if (iss.fail() || !checkFileDelimiter(isDataCsv, delimiter)) {
            printError("invalid file format (\e[3;30m" + line + "\e[31m).\e[0m",
                false);
        }
    }
}

int main(int ac, char** av) {
    if (ac != 2 || !strlen(av[1])) {
        printError("invalid number of arguments.");
        return 1;
    }
    try {
        checkFileExist("data.csv");
        checkFileExist(av[1]);
        checkFileContent("data.csv", true);
        std::cout << "\e[1;32mSuccess: \e[;32mdata.csv is valid.\e[0m"
                  << std::endl;

        checkFileContent(av[1]);
        std::cout << "\e[1;32mSuccess: \e[;32m" << av[1] << " is valid.\e[0m"
                  << std::endl;

    } catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    }

    return 0;
}

// TODO:
// [x] data.csv should be here
// [x] must take a file as an arg
// [] date | value for input
// [] YYYY-MM-DD | value
// [] value is a float between 0 and 1000
// [] date is not before 2009-01-09 (bitcoin creation date)
// [] date is not after the current date
