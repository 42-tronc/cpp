#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    checkFileContent("data.csv", true);
    checkFileContent(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->data = other.data;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        this->data = other.data;

    return *this;
}

void BitcoinExchange::addEntry(const std::string& date, float exchangeRate) {
    this->data[date] = exchangeRate;
}

float BitcoinExchange::getRate(std::string& date) {
    std::map<std::string, float>::iterator it = this->data.find(date);
    if (it != this->data.end())
        return it->second;
    return (--this->data.lower_bound(date))->second;
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
        throw std::runtime_error("date is not in the format YYYY-MM-DD");

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

void getData(bool isDataCsv, std::string& date, double& value,
    const std::string& line, std::string& delimiter) {
    std::istringstream iss(line);
    std::string valueStr;

    if (isDataCsv) {
        std::getline(iss, date, ',');
        if (line.size() < 10)
            throw std::runtime_error("delimiter is missing");
        delimiter = line[10];
    } else {
        std::getline(iss, date, ' ');
        std::getline(iss, delimiter, ' ');
    }
    std::getline(iss, valueStr);

    if (valueStr.find_first_not_of("0123456789.") != std::string::npos)
        throw std::runtime_error("value is not a valid number");

    size_t dots = 0;
    for (size_t i = 0; i < valueStr.length(); i++) {
        if (valueStr[i] == '.')
            dots++;
    }
    if (dots > 1)
        throw std::runtime_error("value can only have one dot");

    std::istringstream issValue(valueStr);
    issValue >> value;

    if (line.length() <= 11 || issValue.fail() || iss.fail() ||
        valueStr.empty())
        throw std::runtime_error("invalid line format");
}

void BitcoinExchange::processLine(const std::string& line, bool isDataCsv) {
    std::string date, delimiter;
    double value = 0;

    try {
        if (line.empty())
            throw std::runtime_error("line is empty");

        getData(isDataCsv, date, value, line, delimiter);

        checkFileDelimiter(isDataCsv, delimiter);
        checkDate(isDataCsv, date);
        if (!isDataCsv && (value < 0 || value > 1000))
            throw std::runtime_error("value is not between 0 and 1000");

        if (isDataCsv)
            addEntry(date, value);
        else {
            float rate = getRate(date);
            std::cout << "\e[95m \e[;m" << date << " | \e[93m\e[;m "
                      << std::setw(3) << value << " | \e[92m\e[;m "
                      << value * rate << std::endl;
        }

    } catch (const std::runtime_error& ex) {
        if (isDataCsv)
            throw;
        printError(ex.what(), WARNING, line, false);
    }
}

void BitcoinExchange::checkFileContent(
    const std::string& filename, bool isDataCsv) {
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
