#include <cstring>
#include <ctime>
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
        prefix = "\e[1;31m[Error] " + colour;
    } else if (level == WARNING) {
        colour = "\e[;33m";
        prefix = "\e[1;33m[Warning] " + colour;
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

bool isFutureDate(int year, int month, int day) {
    std::time_t now = std::time(0);
    std::tm* localTime = std::localtime(&now);

    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;

    if (year > currentYear || (year == currentYear && month > currentMonth) ||
        (year == currentYear && month == currentMonth && day > currentDay))
        return true;

    return false;
}

void checkDate(bool isDataCsv, const std::string& date) {
    if (date.length() != 10)
        throw std::runtime_error("date is not 10 characters long");

    std::istringstream iss(date);
    int year, month, day;
    char delimiter, delimiter2;

    iss >> year >> delimiter >> month >> delimiter2 >> day;
    if (delimiter != '-' || delimiter2 != '-' || iss.fail())
        throw std::runtime_error("date delimiter is not '-'");

    if (month < 1 || month > 12 || day < 1 || day > 31)
        throw std::runtime_error("invalid month or day");
    if (year < 2009 || (!isDataCsv && year == 2009 && month == 1 && day < 3))
        throw std::runtime_error("date is before bitcoin creation date");
    if (isFutureDate(year, month, day))
        throw std::runtime_error("date is in the future");

    // Check the number of days in a month
    if (month == 2 && day > 29 && (year % 4 == 0))
        throw std::runtime_error("February has 29 days in a leap year");
    if (month == 2 && day > 28 && (year % 4 != 0))
        throw std::runtime_error("February has 28 days in a non-leap year");
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::runtime_error(
            "April, June, September, and November have only 30 days");
}

void checkFileContent(const std::string& filename, bool isDataCsv = false) {
    std::ifstream file(filename.c_str());
    std::string line;
    bool isFirstLine = true;

    // Check if the file is empty
    if (file.peek() == EOF || !file.good())
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

        try {
            if (line.empty())
                throw std::runtime_error("line is empty");
            if (isDataCsv) {
                std::getline(iss, date, ',');
                std::getline(iss, valueStr);
                std::istringstream issValue(valueStr);
                issValue >> value;

                if (line.length() < 11)
                    throw std::runtime_error("invalid line format");

                delimiter = line.at(10);
            } else {
                iss >> date >> delimiter >> value;
                if (iss.fail())
                    throw std::runtime_error("invalid line format");
            }

            checkFileDelimiter(isDataCsv, delimiter);
            checkDate(isDataCsv, date);
            if (!isDataCsv && (value < 0 || value > 1000))
                throw std::runtime_error("value is not between 0 and 1000");

            // std::cout << "\e[1mDate: \e[;35m" << date
            //           << "\e[0m | \e[1mValue: \e[;35m" << std::setw(3) <<
            //           value
            //           << "\e[0m" << std::endl;

        } catch (const std::runtime_error& ex) {
            if (isDataCsv)
                throw;
            printError(ex.what(), WARNING, line, false);
        }
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

        // BitcoinExchange btc(av[1]);
        checkFileContent("data.csv", true);
        checkFileContent(av[1]);

    } catch (const std::exception& ex) {
        printError(ex.what(), ERROR);
        return 1;
    }
    std::cout << "\n\e[1;32mSuccess: \e[;32mboth files are valid.\e[0m"
              << std::endl;

    return 0;
}
