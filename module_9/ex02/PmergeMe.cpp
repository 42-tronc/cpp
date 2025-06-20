#include "PmergeMe.hpp"

#include <ctime>

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

    if (container.size() % 2 != 0) {
        max--;
        pairs.push_back(std::make_pair(container[max], -1));
        container.pop_back();
    }

    for (size_t i = 0; i < max; i += 2)
        pairs.push_back(std::make_pair(container[i], container[i + 1]));

    container.clear();
}

template <typename Pairs>
void pairSwap(Pairs& pairs) {
    for (size_t i = 0; i < pairs.size(); i++)
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
}

template <typename Container, typename Pairs>
void pushLargestElementBack(Container& container, Pairs& pairs) {
    for (size_t i = 0; i < pairs.size(); i++)
        container.push_back(pairs[i].first);
}

template <typename Container, typename Pairs>
void pushRemaining(Container& container, Pairs& pairs) {
    for (size_t i = 0; i < pairs.size(); i++) {
        // If there are an odd number of args, skip the pair with the -1
        if (pairs[i].second == -1)
            continue;

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
    pairSwap(pairs);

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

    std::clock_t start = std::clock();
    mergeInsertSort(av, vector, vectorPairs);
    std::clock_t end = std::clock();
    execTimeVector =
        static_cast<double>(end - start) * 1000000 / CLOCKS_PER_SEC;

    start = std::clock();
    mergeInsertSort(av, deque, dequePairs);
    end = std::clock();
    execTimeDeque = static_cast<double>(end - start) * 1000000 / CLOCKS_PER_SEC;

    std::cout << std::endl << std::setw(18) << std::left << "\e[32mAfter\e[;m:";
    for (size_t i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe::~PmergeMe() {}

double PmergeMe::getVectorTime() {
    return this->execTimeVector;
}

double PmergeMe::getDequeTime() {
    return this->execTimeDeque;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        vector = other.vector;
        deque = other.deque;
        execTimeVector = other.execTimeVector;
        execTimeDeque = other.execTimeDeque;
    }
    return *this;
}
