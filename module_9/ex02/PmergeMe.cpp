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
    // std::cout << "Vector: ";
    // printContainer(vector);
    std::cout << "Deque: ";
    printContainer(deque);
}

// FIXME: this is not the correct algorithm
template <typename Container>
void fordJohnsonSort(Container& container) {
    for (typename Container::size_type i = 1; i < container.size(); ++i) {
        typename Container::value_type key = container[i];
        typename Container::size_type j = i;

        // Binary search to find the correct position for key

        while (j > 0 && container[j - 1] > key) {
            container[j] = container[j - 1];
            --j;
        }
        container[j] = key;
    }
}

PmergeMe::PmergeMe(char** av) : execTimeVector(0), execTimeDeque(0) {
    fillContainer(av, vector);
    fillContainer(av, deque);

    std::cout << "\e[1;33mUnsorted list:\e[0m" << std::endl;
    printBothContainers(vector, deque);

    fordJohnsonSort(vector);
    fordJohnsonSort(deque);

    std::cout << "\e[1;33mSorted list:\e[0m" << std::endl;
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
