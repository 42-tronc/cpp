#include "Intern.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main() {
    printAction("Create an Intern");
    Intern intern;

    printAction("Create a Shrubbery Creation AForm");
    AForm* shrub = intern.makeForm("shrubbery creation", "home");

    printAction("Create a Robotomy Request AForm");
    AForm* robot = intern.makeForm("robotomy request", "home");

    printAction("Create a Presidential Pardon AForm");
    AForm* pres = intern.makeForm("presidential pardon", "home");

    printAction("Print the form's stats");
    std::cout << *shrub << std::endl
              << *robot << std::endl
              << *pres << std::endl;

    printAction("Create a Bureaucrat with a High Grade");
    Bureaucrat high("High", 1);

    printAction("Create a Bureaucrat with a Low Grade");
    Bureaucrat low("Low", 150);

    printAction("Create a Bureaucrat with a Normal Grade");
    Bureaucrat normal("Normal", 75);

    printAction("Make the Low Grade Bureaucrat try to sign the forms");
    shrub->beSigned(low);
    robot->beSigned(low);
    pres->beSigned(low);

    printAction("Make the Low Grade Bureaucrat try to execute the forms");
    shrub->execute(low);
    robot->execute(low);
    pres->execute(low);

    printAction("Make the High Grade Bureaucrat try to sign the forms");
    shrub->beSigned(high);
    robot->beSigned(high);
    pres->beSigned(high);

    printAction("High Grade executes Shrubbery Creation");
    shrub->execute(high);

    printAction("High Grade executes Robotomy Request");
    robot->execute(high);

    printAction("High Grade executes Presidential Pardon");
    pres->execute(high);

    printAction("Delete the forms");
    delete shrub;
    delete robot;
    delete pres;

    printAction("Exiting the program");

    return 0;
}
