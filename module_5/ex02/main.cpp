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

    printAction("Create the default ShrubberyCreationForm");
    ShrubberyCreationForm defaultShrubberyCreationForm;
    std::cout << defaultShrubberyCreationForm << std::endl;

    // printAction("Try to sign with a bureaucrat with a grade of 150");
    // defaultShrubberyCreationForm.beSigned(jane);
    // std::cout << defaultShrubberyCreationForm << std::endl;

    // printAction("Create a ShrubberyCreationForm with a target");
    // ShrubberyCreationForm shrubberyCreationForm("Blue");

    // printAction(
    //     "Execute the default ShrubberyCreationForm with the bureaucrat "
    //     "with a grade of 1");
    // defaultShrubberyCreationForm.execute(john);

    // printAction(
    //     "Execute the default ShrubberyCreationForm with the bureaucrat with a
    //     " "grade of 150");
    // defaultShrubberyCreationForm.execute(jane);

    // printAction(
    //     "Execute the ShrubberyCreationForm with a target with the "
    //     "bureaucrat with a grade of 1");
    // shrubberyCreationForm.execute(john);

    // printAction(
    //     "Execute the ShrubberyCreationForm with a target with the "
    //     "bureaucrat with a grade of 150");
    // shrubberyCreationForm.execute(jane);

    // printAction("Create a RobotomyRequestForm with a target");
    // RobotomyRequestForm robotomyRequestForm("Julie");

    // printAction(
    //     "Execute the RobotomyRequestForm with a target with the "
    //     "bureaucrat with a grade of 1");
    // robotomyRequestForm.execute(john);

    // printAction(
    //     "Execute the RobotomyRequestForm with a target with the "
    //     "bureaucrat with a grade of 150");
    // robotomyRequestForm.execute(jane);

    // printAction("Create a PresidentialPardonForm with a target");
    // PresidentialPardonForm presidentialPardonForm("Jackson");

    // printAction(
    //     "Execute the PresidentialPardonForm with a target with the "
    //     "bureaucrat with a grade of 1");
    // presidentialPardonForm.execute(john);

    // printAction(
    //     "Execute the PresidentialPardonForm with a target with the "
    //     "bureaucrat with a grade of 150");
    // presidentialPardonForm.execute(jane);

    printAction("Exiting the program");

    return 0;
}
