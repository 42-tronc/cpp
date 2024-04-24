#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <vector>

inline void printError(const std::string &message) {
    std::string colour, prefix;
    colour = "\e[;31m";
    prefix = colour + "\e[1m[Error]: " + colour;

    std::cout << prefix << message << ".\e[0m" << std::endl;

    std::cout << "\n\e[1;33mUsage: \e[;33m./PmergeMe [positive int] [positive "
              << "int] ...\e[0m" << std::endl;
}

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    ~PmergeMe();

    PmergeMe &operator=(const PmergeMe &other);

private:
    std::vector<int> vector;
    std::deque<int> deque;
    double execTimeVector;
    double execTimeDeque;
};

#endif
