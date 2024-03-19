#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main() {
    printAction("Create a Bureaucrat with a grade of 1");
    Bureaucrat john("John", 1);

    printAction("Create a Bureaucrat with a grade of 150");
    Bureaucrat jane("Jane", 150);

    printAction("Create a Bureaucrat with a grade of 72");
    Bureaucrat jill("Jill", 72);

    printAction("Create a Bureaucrat with a grade of 45");
    Bureaucrat jack("Jack", 45);

    /* SHRUBBERY CREATION FORM */
    printAction("Create the default ShrubberyCreationForm");
    ShrubberyCreationForm defaultShrubberyCreationForm;
    std::cout << defaultShrubberyCreationForm << std::endl;

    printAction("Try to execute the default ShrubberyCreationForm with John");
    std::cout << john << std::endl;
    defaultShrubberyCreationForm.execute(john);

    printAction("Try to sign the default ShrubberyCreationForm with John");
    std::cout << john << std::endl;
    defaultShrubberyCreationForm.beSigned(john);

    printAction("Try to execute the default ShrubberyCreationForm with Jane");
    std::cout << jane << std::endl << defaultShrubberyCreationForm << std::endl;
    defaultShrubberyCreationForm.execute(jane);

    printAction("Try to execute the default ShrubberyCreationForm with Jill");
    std::cout << jill << std::endl;
    defaultShrubberyCreationForm.execute(jill);

    printAction("Create a ShrubberyCreationForm with a target");
    ShrubberyCreationForm shrubberyCreationForm("Blue");

    printAction("Sign and execute the ShrubberyCreationForm with John");
    shrubberyCreationForm.beSigned(john);
    shrubberyCreationForm.execute(john);

    /* ROBOTOMY REQUEST FORM */
    printAction("Create a RobotomyRequestForm with a target");
    RobotomyRequestForm robotomyRequestForm("Julie");

    printAction("Execute the RobotomyRequestForm with Jack");
    robotomyRequestForm.execute(jack);

    printAction("Sign and execute the RobotomyRequestForm with Jill");
    robotomyRequestForm.beSigned(jill);
    robotomyRequestForm.execute(jill);

    printAction("Execute the RobotomyRequestForm with Jack");
    robotomyRequestForm.execute(jack);

    /* PRESIDENTIAL PARDON FORM */
    printAction("Create a PresidentialPardonForm with a target");
    PresidentialPardonForm presidentialPardonForm("Jackson");

    printAction("Sign and execute the PresidentialPardonForm with Jack");
    jack.signAForm(presidentialPardonForm);
    jack.executeAForm(presidentialPardonForm);

    printAction("Sign and execute the PresidentialPardonForm with John");
    john.signAForm(presidentialPardonForm);
    john.executeAForm(presidentialPardonForm);

    printAction("Exiting the program");

    return 0;
}
