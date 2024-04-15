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

    printAction("Add 15000 numbers to the big Span");
    for (int i = 0; i < 15000; i++) {
        bigSpan.addNumber(i);
    }

    printAction("Return the shortest span of the big Span");
    std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;

    printAction("Return the longest span of the big Span");
    std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

    return 0;
}
