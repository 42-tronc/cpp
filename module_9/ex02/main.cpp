#include <iostream>

#include "PmergeMe.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n" << std::endl;
}

void isValidInput(int ac, char* av[]) {
    for (int i = 1; i < ac; i++) {
        std::string str = av[i];

        if (str.empty())
            throw std::invalid_argument("empty argument");
        // check if the string contains only digits
        if (str.find_first_not_of("0123456789") != std::string::npos)
            throw std::invalid_argument("invalid argument (" + str + ")");
        // check for duplicates
        for (int j = i + 1; j < ac; j++) {
            if (str == av[j])
                throw std::invalid_argument("duplicate argument (" + str + ")");
        }

        std::istringstream iss(str);
        long num;
        iss >> num;
        if (iss.fail())
            throw std::invalid_argument("invalid argument (" + str + ")");
        if (num > std::numeric_limits<int>::max())
            throw std::invalid_argument("number is over the int limit");
        else if (num < 0)
            throw std::invalid_argument("number is negative");
    }

    std::cout << std::setw(18) << std::left << "\e[35mBefore\e[;m:";
    for (int i = 1; i < ac; i++)
        std::cout << av[i] << " ";
}

int main(int ac, char* av[]) {
    try {
        if (ac < 2)
            throw std::invalid_argument("invalid number of arguments");
        isValidInput(ac, av);

        PmergeMe pmergeMe(av);
    } catch (const std::exception& ex) {
        printError(ex.what());
        return 1;
    }

    std::cout << "\n\e[1;32mSuccess\e[;32m - All arguments are valid.\e[0m\n"
              << std::endl;

    return 0;
}

/* TODO:
[x] take positive int as args
[x] use one of those 2 containers: deque, vector, ~list~
[x] error to cout
[x] duplicate error
[] use the merge-insertion sort algorithm (Ford-Johnson algorithm)
[] take at least 3000 ints
[] 1st line print the unsorted list
[] 2nd line print the sorted list
[] 3rd line print the exec time
[] 4th line print the exec time



*/
