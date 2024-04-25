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
}

template <typename Container, typename Pairs>
void pushRemaining(Container& container, Pairs& pairs) {
    for (size_t i = 0; i < pairs.size(); i++)
        container.insert(std::lower_bound(container.begin(), container.end(),
                             pairs[i].second),
            pairs[i].second);
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
    std::vector<std::pair<int, int> > vectorPairs;
    splitCollection(vector, vectorPairs);

    std::deque<std::pair<int, int> > dequePairs;
    splitCollection(deque, dequePairs);

    printBothPairs(vectorPairs, dequePairs);

    //////////////////////////////////////////
    // Compare the pairs to find the largest element
    std::cout << "\n\e[34mCompare the pairs to find the largest element\e[;m\n";
    std::cout << "\e[35mVector pairs: \e[;m" << std::endl;
    pairSort(vectorPairs);
    printPairs(vectorPairs);
    std::cout << "on the side: ";
    printContainer(vector);

    std::cout << "\n\e[35mDeque pairs: \e[;m" << std::endl;
    pairSort(dequePairs);
    printPairs(dequePairs);
    std::cout << "on the side: ";
    printContainer(deque);

    //////////////////////////////////////////
    // Sort the pair container
    std::cout << "\n\e[34mSort the pair container\e[;m\n";
    std::sort(dequePairs.begin(), dequePairs.end());
    std::sort(vectorPairs.begin(), vectorPairs.end());
    printBothPairs(vectorPairs, dequePairs);

    //////////////////////////////////////////
    // Push the largest element of each pair back to the container
    std::cout << "\n\e[34mPush the largest element of each pair back to the "
                 "container\e[;m\n";
    std::cout << "\e[35mVector: \e[;m" << std::endl;
    pushLargestElementBack(vector, vectorPairs);
    std::sort(vector.begin(), vector.end());
    printContainer(vector);

    std::cout << "\n\e[35mDeque: \e[;m" << std::endl;
    pushLargestElementBack(deque, dequePairs);
    std::sort(deque.begin(), deque.end());
    printContainer(deque);

    //////////////////////////////////////////
    // Insert at the right position the remaining elements from the pair
    std::cout << "\n\e[34mInsert the remaining elements from the pair "
                 "container\e[;m\n";
    pushRemaining(vector, vectorPairs);
    pushRemaining(deque, dequePairs);
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
