#include "PmergeMe.hpp"

#include <iomanip>

// TODO: REMOVE ME
template <typename T>
void printContainer(const T& container) {
    for (size_t i = 0; i < container.size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

template <typename Pairs>
void printPairs(const Pairs& pairs) {
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << std::setw(5) << pairs[i].first << " " << std::setw(5)
                  << pairs[i].second << " " << std::endl;
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

void printBothPairs(const std::vector<std::pair<int, int> >& vectorPairs,
    const std::deque<std::pair<int, int> >& dequePairs) {
    std::cout << "\e[35mVector pairs: \e[;m" << std::endl;
    printPairs(vectorPairs);
    std::cout << "\e[35mDeque pairs: \e[;m" << std::endl;
    printPairs(dequePairs);
}
//////////////////////////////////////////

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

template <typename Container, typename Pairs>
void splitCollection(Container& container, Pairs& pairs) {
    size_t max = container.size();

    // If the size is odd, save it and pop it
    // TODO: put the odd element in a separate container or pair
    int save = -1;
    if (container.size() % 2 != 0) {
        max--;
        // save = container[max];
        pairs.push_back(std::make_pair(container[max], -1));
        container.pop_back();
    }

    for (size_t i = 0; i < max; i += 2) {
        pairs.push_back(std::make_pair(container[i], container[i + 1]));
        // container.pop_back();
        // container.pop_back();
    }
    printPairs(pairs);
    container.clear();

    // If the size is odd, push the last element back
    if (save != -1)
        container.push_back(save);
}

template <typename Pairs>
void pairSort(Pairs& pairs) {
    for (size_t i = 0; i < pairs.size(); i++)
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
}

template <typename Container, typename Pairs>
void pushLargestElementBack(Container& container, Pairs& pairs) {
    for (size_t i = 0; i < pairs.size(); i++)
        container.push_back(pairs[i].first);
    // std::sort(container.begin(), container.end());
}

template <typename Container, typename Pairs>
void pushRemaining(Container& container, Pairs& pairs) {
    for (size_t i = 0; i < pairs.size(); i++) {
        // Determine the maximum position for insertion based on the first
        // element of the pair
        typename Container::iterator maxPos =
            container.begin() +
            std::min(pairs[i].first, static_cast<int>(container.size()) - 1);

        // Find the position to insert pairs[i].second in the sorted container,
        // up to maxPos
        typename Container::iterator it =
            std::lower_bound(container.begin(), maxPos, pairs[i].second);

        // Insert pairs[i].second at the found position
        container.insert(it, pairs[i].second);
    }
}

template <typename Container, typename Pairs>
void mergeInsertSort(char** av, Container& container, Pairs& pairs) {
    // Fill the container with the input arguments
    fillContainer(av, container);

    // Group the elements in n/2 pairs
    splitCollection(container, pairs);

    // Compare the pairs to find the largest element
    pairSort(pairs);

    // Sort the pair container
    std::sort(pairs.begin(), pairs.end());

    // Push the largest element of each pair back to the container
    pushLargestElementBack(container, pairs);

    // Insert at the right position the remaining elements from the pair
    pushRemaining(container, pairs);
}

PmergeMe::PmergeMe(char** av) : execTimeVector(0), execTimeDeque(0) {
    std::vector<std::pair<int, int> > vectorPairs;
    std::deque<std::pair<int, int> > dequePairs;

    mergeInsertSort(av, vector, vectorPairs);
    mergeInsertSort(av, deque, dequePairs);

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
