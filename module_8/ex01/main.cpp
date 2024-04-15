#include <fstream>

#include "Span.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n" << std::endl;
}

int main(void) {
    printAction("Create a default Span");
    Span defaultSpan;

    printAction("Try to add a number to the default Span");
    defaultSpan.addNumber(42);

    printAction("Create a Span with 0 elements");
    Span emptySpan(0);

    printAction("Try to add a number to the Span with 0 elements");
    emptySpan.addNumber(42);

    printAction(
        "Try to calculate the shortest span of the Span with 0 elements");
    emptySpan.shortestSpan();

    printAction(
        "Try to calculate the longest span of the Span with 0 elements");
    emptySpan.longestSpan();

    printAction("Create a Span with 5 elements");
    Span span(5);
    span.addNumber(6);
    span.addNumber(3);
    span.addNumber(17);
    span.addNumber(9);
    span.addNumber(11);

    printAction("Try to add a 6th number to the Span with 5 elements");
    span.addNumber(42);

    printAction("Return the shortest span");
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;

    printAction("Return the longest span");
    std::cout << "Longest span: " << span.longestSpan() << std::endl;

    printAction("Create a copy of the Span with 5 elements");
    Span copySpan(span);

    printAction("Create a Span and assign the copy to it");
    Span assignedSpan = copySpan;

    printAction("Create a span with over 10000 elements");
    Span bigSpan(15000);
    std::vector<int> numbers(15000);
    for (int i = 0; i < 15000; i++)
        numbers[i] = i;

    printAction("Fill the big Span with 15000 numbers");
    bigSpan.fillSpan(numbers.begin(), numbers.end());

    printAction("Try to add a 15000th number to the big Span");
    bigSpan.addNumber(42);

    printAction("Show some numbers of the big Span");
    for (int i = 0; i < 10; i++)
        std::cout << bigSpan.getNumberAt(i) << " ";
    std::cout << std::endl;
    for (int i = 14990; i < 15000; i++)
        std::cout << bigSpan.getNumberAt(i) << " ";

    printAction("Return the shortest span of the big Span");
    std::cout << "\e[1mShortest span: \e[0m" << bigSpan.shortestSpan()
              << std::endl;

    printAction("Return the longest span of the big Span");
    std::cout << "\e[1mLongest span: \e[0m" << bigSpan.longestSpan()
              << std::endl;

    return 0;
}
