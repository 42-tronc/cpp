#include "Span.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n" << std::endl;
}

int main(void) {
    printAction("hey");
    Span span;

    printAction("spanCopy");
    Span spanCopy(span);

    printAction("spanAssigned");
    Span spanAssigned = span;

    printAction("span2");
    Span span2(10);

    (void)spanAssigned;

    return 0;
}
