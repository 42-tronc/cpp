#include "Span.hpp"

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

Span& Span::operator=(const Span& other) {
    if (this == &other)
        return *this;
    N = other.N;
    std::cout << "\e[32mSpan assigned\e[0m" << std::endl;
    return *this;
}
