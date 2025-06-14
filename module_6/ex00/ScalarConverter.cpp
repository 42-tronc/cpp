#include "ScalarConverter.hpp"

#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

template <typename T>
void printResult(const std::string& type, const T& result) {
    std::cout << std::setw(6) << std::left << type << ": " << result
              << std::endl;
}

/**
 * @brief This function checks if the input string contains "nan" or "inf"
 *
 * find() returns the position of the first occurrence of the substring in the
 * string. If the substring is not found, the function returns
 * std::string::npos.
 */
bool isPseudoLiteral(const std::string& inputStr) {
    return (inputStr == "nan" || inputStr == "inf" || inputStr == "-inf" ||
            inputStr == "+inf" || inputStr == "+inff" || inputStr == "-inff");
}

bool erroredInput(std::string inputStr) {
    size_t i = 0;
    if (inputStr[i] == '+' || inputStr[i] == '-')
        i++;

    while (isdigit(inputStr[i])) {
        i++;
    }

    if (i == inputStr.size())
        return (false);
    if (inputStr[i] == '.' && isdigit(inputStr[i + 1])) {
        i++;
        while (isdigit(inputStr[i])) {
            i++;
        }
    }
    if (i == inputStr.size())
        return (false);
    if (inputStr[i] == 'f' && i + 1 == inputStr.size())
        return (false);
    return (true);
}

void convertChar(const std::string& inputStr, long double ld) {
    if (isPseudoLiteral(inputStr) || inputStr.empty() ||
        ld > std::numeric_limits<char>::max() ||
        ld < std::numeric_limits<char>::min())
        printResult("Char", "impossible");
    else if (ld < 32 || ld > 126) {
        printResult("Char", "non displayable");
    } else {
        char c = static_cast<char>(ld);
        std::stringstream ss;
        ss << "'" << c << "'";
        printResult("Char", ss.str());
    }
}

void convertInt(const std::string& inputStr, long double ld) {
    if (isPseudoLiteral(inputStr) || ld < std::numeric_limits<int>::min() ||
        ld > std::numeric_limits<int>::max())
        printResult("Int", "impossible");
    else
        printResult("Int", static_cast<int>(ld));
}

void convertFloat(const std::string& inputStr, long double ld) {
    if (isPseudoLiteral(inputStr)) {
        if (inputStr.find("ff") != std::string::npos)
            printResult("Float", inputStr);
        else
            printResult("Float", inputStr + "f");
    } else if (ld < -std::numeric_limits<float>::max() ||
               ld > std::numeric_limits<float>::max())
        printResult("Float", "impossible");
    else {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) << static_cast<float>(ld)
           << "f";
        printResult("Float", ss.str());
    }
}

void convertDouble(const std::string& inputStr, long double ld) {
    if (isPseudoLiteral(inputStr)) {
        if (inputStr.find("ff") != std::string::npos)
            printResult("Double", inputStr.substr(0, inputStr.size() - 1));
        else
            printResult("Double", inputStr);
    } else if (ld < -std::numeric_limits<double>::max() ||
               ld > std::numeric_limits<double>::max())
        printResult("Double", "impossible");
    else {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) << static_cast<double>(ld);
        printResult("Double", ss.str());
    }
}

void ScalarConverter::convert(const std::string& inputStr) {
    long double ld;
    std::istringstream iss(inputStr);
    if (inputStr.size() == 1 && !std::isdigit(inputStr[0]))
        ld = static_cast<long double>(inputStr[0]);
    else
        iss >> ld;

    if (inputStr.empty() || (iss.fail() && !isPseudoLiteral(inputStr)) ||
        (!iss.fail() && erroredInput(inputStr) && inputStr.size() > 1)) {
        std::cerr << "\e[1;31mError: \e[;31mInvalid input.\e[0m" << std::endl;
        return;
    }
    convertChar(inputStr, ld);
    convertInt(inputStr, ld);
    convertFloat(inputStr, ld);
    convertDouble(inputStr, ld);
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}
