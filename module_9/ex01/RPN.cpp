#include "RPN.hpp"

RPN::RPN(const std::string& expression) {
    isValidInput(expression);
    calculateExpression(expression);
}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other) {
    return *this;
}

bool isValidOperator(const char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

bool isValidDigit(const char digit) {
    return digit >= '0' && digit <= '9';
}

void RPN::isValidInput(const std::string& expression) const {
    if (expression.empty())
        throw std::runtime_error("empty expression");

    std::istringstream iss(expression);
    std::string token;
    size_t digits = 0;
    size_t operators = 0;

    while (iss >> token) {
        if (token.size() != 1)
            throw std::runtime_error("invalid token size");

        char element = token[0];
        if (isValidDigit(element)) {
            digits++;
        } else if (isValidOperator(element)) {
            operators++;
        } else {
            throw std::runtime_error(
                "invalid character (" + std::string(1, element) + ")");
        }
    }

    if (digits < 2)
        throw std::runtime_error("expression must have at least 2 numbers");
    else if (operators != digits - 1) {
        std::ostringstream oss;
        oss << "found " << operators << " operators, expected " << (digits - 1);
        std::string message = oss.str();

        throw std::runtime_error(message);
    }
}

void RPN::calculateExpression(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isValidDigit(token[0])) {
            stack.push(token[0] - '0');
        } else if (isValidOperator(token[0])) {
            if (stack.size() < 2)
                throw std::runtime_error(
                    "not enough numbers to perform operation");

            short b = stack.top();
            stack.pop();
            short a = stack.top();
            stack.pop();

            switch (token[0]) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    if (b == 0)
                        throw std::runtime_error("division by zero");
                    stack.push(a / b);
                    break;
            }
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("invalid expression");

    std::cout << "\e[1;32mResult: \e[;32m" << stack.top() << "\e[0m"
              << std::endl;
}
