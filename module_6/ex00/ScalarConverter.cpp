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
    return (inputStr.find("nan") != std::string::npos ||
            inputStr.find("inf") != std::string::npos);
}

void convertChar(const std::string& inputStr) {
    char c = static_cast<char>(atoi(inputStr.c_str()));

    if (isPseudoLiteral(inputStr))
        printResult("Char", "impossible");
    else if (c < 32 || c > 126)
        printResult("Char", "non displayable");
    else {
        std::stringstream ss;
        ss << "'" << c << "'";
        printResult("Char", ss.str());
    }
}

void convertInt(const std::string& inputStr) {
    std::istringstream iss(inputStr);
    long inputLong;
    iss >> inputLong;

    if (isPseudoLiteral(inputStr) ||
        inputLong < std::numeric_limits<int>::min() ||
        inputLong > std::numeric_limits<int>::max())
        printResult("Int", "impossible");
    else
        printResult("Int", static_cast<int>(inputLong));
}

void convertFloat(const std::string& inputStr) {
    std::istringstream iss(inputStr);
    double f;
    iss >> f;

    if (isPseudoLiteral(inputStr))
        printResult("Float", inputStr + "f");
    else if (f < -std::numeric_limits<float>::max() ||
             f > std::numeric_limits<float>::max())
        printResult("Float", "impossible");
    else {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) << f
           << "f";  // Format float with one decimal place and append "f"
        printResult("Float", ss.str());
    }
}

void convertDouble(const std::string& inputStr) {
    std::istringstream iss(inputStr);
    double d;
    iss >> d;

    if (isPseudoLiteral(inputStr))
        printResult("Double", inputStr);
    else if (d < -std::numeric_limits<double>::max() ||
             d > std::numeric_limits<double>::max())
        printResult("Double", "impossible");
    else {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) << d;
        printResult("Double", ss.str());
    }
}

void ScalarConverter::convert(const std::string& inputStr) {
    convertChar(inputStr);
    convertInt(inputStr);
    convertFloat(inputStr);
    convertDouble(inputStr);
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}
