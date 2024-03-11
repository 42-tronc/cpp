#include "Bureaucrat.hpp"
#include "Form.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main() {
    printAction("Create the default Form");
    Form defaultForm;

    printAction("Create a Form with a grade to sign and execute");
    Form fakePassport("Fake Passport", 100, 100);

    printAction("Create a Form with a grade to sign too high");
    Form signTooHigh("Grade Sign Too High", 0, 100);

    printAction("Create a Form with a grade to sign too low");
    Form signTooLow("Grade Sign Too Low", 100, 151);

    printAction("Create a Form with a grade to execute too high");
    Form execTooHigh("Grade Execute Too High", 100, 0);

    printAction("Create a Form with a grade to execute too low");
    Form execTooLow("Grade Execute Too Low", 100, 151);

    // printAction("Creating a Form with a grade too high");
    // Form tooHigh("TooHigh", 0, 100);

    // printAction("Creating a Form with a grade too low");
    // Form tooLow("TooLow", 100, 151);

    // printAction("Creating a Bureaucrat with a grade too high");
    // Bureaucrat tooHigh("TooHigh", 0);

    // printAction("Creating a Bureaucrat with a grade too low");
    // Bureaucrat tooLow("TooLow", 151);

    // printAction("Creating a Bureaucrat with a valid grade");
    // Bureaucrat haulande("Francois Haulande", 100);

    // printAction("Increment the grade of a Bureaucrat");
    // haulande.incrementGrade();

    // printAction("Creating a new Bureaucrat and decrementing its grade");
    // Bureaucrat macaron("Emmanuel Macaron", 149);
    // macaron.decrementGrade();

    // printAction("Decreasing the grade of a Bureaucrat with a grade too low");
    // macaron.decrementGrade();

    // printAction("Creating a copy of a Bureaucrat");
    // Bureaucrat copy(macaron);

    // printAction("Creating a copy with the assignment operator");
    // Bureaucrat copy2 = haulande;

    // printAction("Using the operator<< to print all the Bureaucrats");
    // std::cout << tooHigh << "\n"
    //           << tooLow << "\n"
    //           << haulande << "\n"
    //           << macaron << "\n"
    //           << copy << "\n"
    //           << copy2 << std::endl;

    printAction("Exiting the program");

    return 0;
}
