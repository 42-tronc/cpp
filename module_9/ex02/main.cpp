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
        // for (int j = i + 1; j < ac; j++) {
        //     if (str == av[j])
        //         throw std::invalid_argument("duplicate argument (" + str +
        //         ")");
        // }

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

    std::cout << std::setw(18) << std::left << "\e[31mBefore\e[;m:";
    for (int i = 1; i < ac; i++)
        std::cout << av[i] << " ";
}

int main(int ac, char* av[]) {
    try {
        if (ac < 2)
            throw std::invalid_argument("invalid number of arguments");
        isValidInput(ac, av);

        PmergeMe pmergeMe(av);

        std::cout << "\n\n\e[33mProcess time for " << ac - 1 << " elements\n"
                  << std::setw(13) << std::left << "\e[35mVector:\e[;m"
                  << std::setw(5) << std::right << pmergeMe.getVectorTime()
                  << " µs\n"
                  << std::setw(13) << std::left << "\e[35mDeque:\e[;m"
                  << std::setw(5) << std::right << pmergeMe.getDequeTime()
                  << " µs\n"
                  << std::endl;

    } catch (const std::exception& ex) {
        printError(ex.what());
        return 1;
    }

    return 0;
}
