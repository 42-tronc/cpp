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

void getData(bool isDataCsv, std::string& date, float& value,
    const std::string& line, std::string& delimiter) {
    std::istringstream iss(line);

    if (isDataCsv) {
        std::string valueStr;
        std::getline(iss, date, ',');
        std::getline(iss, valueStr);

        std::istringstream issValue(valueStr);
        issValue >> value;

        if (line.length() <= 11 || issValue.fail() || iss.fail() ||
            valueStr.empty())
            throw std::runtime_error("invalid line format");
        delimiter = line.at(10);
    } else {
        iss >> date >> delimiter >> value;
        if (iss.fail())
            throw std::runtime_error("invalid line format");
    }
}

void processLine(const std::string& line, bool isDataCsv) {
    std::string date, delimiter;
    float value = 0;

    try {
        if (line.empty())
            throw std::runtime_error("line is empty");

        getData(isDataCsv, date, value, line, delimiter);

        checkFileDelimiter(isDataCsv, delimiter);
        checkDate(isDataCsv, date);
        if (!isDataCsv && (value < 0 || value > 1000))
            throw std::runtime_error("value is not between 0 and 1000");

    } catch (const std::runtime_error& ex) {
        if (isDataCsv)
            throw;
        printError(ex.what(), WARNING, line, false);
    }
}

void checkFileContent(const std::string& filename, bool isDataCsv = false) {
    std::ifstream file(filename.c_str());
    std::string line;
    bool isFirstLine = true;

    if (file.peek() == EOF || !file.good())
        throw std::runtime_error(filename + " is empty");

    while (std::getline(file, line)) {
        if (isFirstLine && checkFileHeader(isDataCsv, line)) {
            isFirstLine = false;
            continue;
        }
        processLine(line, isDataCsv);
    }
}
