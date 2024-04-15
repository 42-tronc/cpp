#include "Span.hpp"

void printError(const std::string& str) {
    std::cout << "\e[1;31m Error: \e[;31m" << str << "\e[0m" << std::endl;
}

bool checkSize(const std::vector<int>& numbers) {
    try {
        if (numbers.size() < 2)
            throw std::out_of_range("Span has less than 2 numbers");
    } catch (std::out_of_range& ex) {
        printError(ex.what());
        return false;
    }
    return true;
}

Span::Span() : N(0) {
    std::cout << "\e[32mSpan default created\e[0m" << std::endl;
}

Span::Span(unsigned int N) : N(N) {
    std::cout << "\e[32mSpan created\e[0m" << std::endl;
}

Span::Span(const Span& other) {
    *this = other;
    std::cout << "\e[32mSpan copy created\e[0m" << std::endl;
}

Span::~Span() {
    std::cout << "\e[31mSpan destroyed\e[0m" << std::endl;
}

Span& Span::operator=(const Span& other) {
    if (this == &other)
        return *this;
    N = other.N;
    std::cout << "\e[32mSpan assigned\e[0m" << std::endl;
    return *this;
}

void Span::addNumber(int number) {
    try {
        if (numbers.size() >= N)
            throw std::out_of_range("Span is full");
        numbers.push_back(number);
        std::cout << "\e[33m Number added: \e[1m" << number << "\e[0m"
                  << std::endl;
    } catch (std::out_of_range& ex) {
        printError(ex.what());
    }
}

unsigned int Span::shortestSpan() {
    if (!checkSize(numbers))
        return 0;
    std::sort(numbers.begin(), numbers.end());

    unsigned int shortest = UINT_MAX;
    for (size_t i = 0; i < numbers.size() - 1; i++) {
        unsigned int diff = numbers[i + 1] - numbers[i];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

unsigned int Span::longestSpan() {
    if (!checkSize(numbers))
        return 0;

    return *std::max_element(numbers.begin(), numbers.end()) -
           *std::min_element(numbers.begin(), numbers.end());
}

void Span::fillSpan(
    std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    try {
        if (std::distance(begin, end) > N)
            throw std::out_of_range("Span is too small");
        numbers.assign(begin, end);
        std::cout << "\e[33m Span filled\e[0m" << std::endl;
    } catch (std::out_of_range& ex) {
        printError(ex.what());
    }
}

unsigned int Span::getNumberAt(unsigned int index) {
    return numbers[index];
}
