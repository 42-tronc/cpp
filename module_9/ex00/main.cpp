#include <iomanip>
#include <iostream>

#include "BitcoinExchange.hpp"

void printError(const std::string& message, bool usage = true) {
    std::cerr << "\e[1;31mError: \e[;31m" << message << "\e[0m" << std::endl;
    if (usage)
        std::cerr << "\n\e[1;33mUsage: \e[;33m./btc <file>\e[0m" << std::endl;
}

// bool isParsedDateValid(const std::string& date) {
//     std::istringstream iss(date);
//     short year, month, day;
//     char dash1, dash2;

//     iss >> year >> dash1 >> month >> dash2 >> day;
//     std::cout << "\e[1;32mParsed date: \e[;35m" << year << "\e[0m-"
//               << "\e[35m" << month << "\e[;m-"
//               << "\e[35m" << day << "\e[;m" << std::endl;
//     std::cout << "DAY: " << day << std::endl;
//     if (iss.fail() || dash1 != '-' || dash2 != '-') {
//         return false;
//     }

//     if (year < 2009 || year > 2021) {
//         return false;
//     }

//     return true;
// }

void getDates(const std::string& filename) {
    std::ifstream file(filename.c_str());
    std::string line, date, pipe;
    float value;
    bool isFirstLine = true;

    while (std::getline(file, line)) {
        if (isFirstLine && line == "date | value") {
            isFirstLine = false;
            continue;
        }

        std::istringstream iss(line);
        iss >> date >> pipe >> value;

        std::cout << "\e[1mDate: \e[;35m" << std::setw(10) << date
                  << "\e[0m | \e[1mValue: \e[;35m" << std::setw(3) << value
                  << "\e[0m iss: \e[31m" << iss.fail() << "\e[0m pipe: `\e[31m"
                  << pipe << "\e[0m`" << std::endl;
        if (iss.fail() || pipe != "|") {
            printError("invalid file format.", false);
        }
    }
}

int main(int ac, char** av) {
    (void)av;
    if (ac != 2) {
        printError("invalid number of arguments.");
        return 1;
    }
    if (BitcoinExchange::isFileMissing("data.csv")) {
        printError("data.csv is missing.");
        return 1;
    } else if (BitcoinExchange::isFileMissing(av[1])) {
        printError(std::string(av[1]) + " is missing.");
        return 1;
    }
    // isParsedDateValid("2021-01-01");
    getDates(av[1]);

    std::cout << "\e[1;32mSuccess: \e[;32m" << av[1] << " is valid.\e[0m"
              << std::endl;

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
