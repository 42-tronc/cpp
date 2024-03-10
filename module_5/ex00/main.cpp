#include "Bureaucrat.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main() {
    printAction("Creating a Bureaucrat with a grade too high");
    Bureaucrat tooHigh("TooHigh", 0);

    printAction("Creating a Bureaucrat with a grade too low");
    Bureaucrat tooLow("TooLow", 151);

    printAction("Creating a Bureaucrat with a valid grade");
    Bureaucrat haulande("Francois Haulande", 100);

    printAction("Increment the grade of a Bureaucrat");
    haulande.incrementGrade();

    printAction("Creating a new Bureaucrat and decrementing its grade");
    Bureaucrat macaron("Emmanuel Macaron", 149);
    macaron.decrementGrade();

    printAction("Decreasing the grade of a Bureaucrat with a grade too low");
    macaron.decrementGrade();

    printAction("Creating a copy of a Bureaucrat");
    Bureaucrat copy(macaron);

    printAction("Creating a copy with the assignment operator");
    Bureaucrat copy2 = haulande;

    printAction("Using the operator<< to print all the Bureaucrats");
    std::cout << tooHigh << "\n"
              << tooLow << "\n"
              << haulande << "\n"
              << macaron << "\n"
              << copy << "\n"
              << copy2 << std::endl;

    printAction("Exiting the program");

    return 0;
}
