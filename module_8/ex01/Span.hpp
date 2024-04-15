#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Span {
public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);

    Span& operator=(const Span& other);

    void addNumber(int number);

    unsigned int shortestSpan();
    unsigned int longestSpan();

private:
    unsigned int N;
    std::vector<int> numbers;
};

#endif
