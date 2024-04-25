#include "PmergeMe.hpp"

template <typename T>
void printContainer(const T& container) {
    for (size_t i = 0; i < container.size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void fillContainer(char** av, T& container) {
    for (int i = 1; av[i]; i++) {
        std::istringstream iss(av[i]);
        int num;
        iss >> num;
        if (iss.fail() || num < 0)
            throw std::invalid_argument(
                "invalid argument (" + std::string(av[i]) + ")");

        container.push_back(num);
    }
}

void printBothContainers(
    const std::vector<int>& vector, const std::deque<int>& deque) {
    (void)vector;
    std::cout << "\e[35mVector: \e[;m";
    printContainer(vector);
    std::cout << "\e[35mDeque: \e[;m";
    printContainer(deque);
}

template <typename Container, typename Pairs>
void splitCollection(Container& container, Pairs& pairs) {
    size_t max = container.size();

    // If the size is odd, save it and pop it
    int save = -1;
    if (container.size() % 2 != 0) {
        max--;
        save = container[max];
        container.pop_back();
    }

    for (size_t i = 0; i < max; i += 2) {
        pairs.push_back(std::make_pair(container[i], container[i + 1]));
        container.pop_back();
        container.pop_back();
    }

    // If the size is odd, push the last element back
    if (save != -1)
        container.push_back(save);
}

// TODO: REMOVE ME
template <typename Pairs>
void printPairs(const Pairs& pairs) {
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << std::setw(5) << pairs[i].first << " " << std::setw(5)
                  << pairs[i].second << " " << std::endl;
    }
}

PmergeMe::PmergeMe(char** av) : execTimeVector(0), execTimeDeque(0) {
    //////////////////////////////////////////
    // Fill both containers with the input arguments
    std::cout << "\e[34mFill both containers with the input arguments\e[;m\n";
    fillContainer(av, vector);
    fillContainer(av, deque);

    //////////////////////////////////////////
    // Group the elements in n/2 pairs
    std::cout << "\n\e[34mGroup the elements in n/2 pairs\e[;m\n";
    std::cout << "\e[35mVector pairs: \e[;m" << std::endl;
    std::vector<std::pair<int, int> > vectorPairs;
    splitCollection(vector, vectorPairs);
    printPairs(vectorPairs);

    std::cout << "\n\e[35mDeque pairs: \e[;m" << std::endl;
    std::deque<std::pair<int, int> > dequePairs;
    splitCollection(deque, dequePairs);
    printPairs(dequePairs);

    printBothContainers(vector, deque);
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        vector = other.vector;
        deque = other.deque;
        execTimeVector = other.execTimeVector;
        execTimeDeque = other.execTimeDeque;
    }
    return *this;
}
