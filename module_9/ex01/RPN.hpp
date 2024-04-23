#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>  // cerr, cout, endl
#include <sstream>   // istringstream
#include <stack>     // stack

inline void printError(
    const std::string &message, const std::string &details = "") {
    std::string colour, prefix;
    colour = "\e[;31m";
    prefix = colour + "\e[1m[Error]: " + colour;

    std::cerr << prefix << message;
    if (!details.empty())
        std::cerr << " (\e[3;30m" << details << colour << ")";
    std::cerr << ".\e[0m" << std::endl;

    std::cerr << "\n\e[1;33mUsage: \e[;33m./RPN \"<expression>\"\e[0m"
              << std::endl;
}

class RPN {
public:
    RPN(const std::string &expression);
    RPN(const RPN &other);
    ~RPN();

    RPN &operator=(const RPN &other);

    void isValidInput(const std::string &expression) const;
    void calculateExpression(const std::string &expression);

private:
    RPN();
    std::stack<short> stack;
};

#endif
