#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
public:
    static void convert(const std::string& input);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ~ScalarConverter();

    ScalarConverter& operator=(const ScalarConverter& other);
};

#endif
