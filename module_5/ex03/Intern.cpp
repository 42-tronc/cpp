#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern &other) {
    std::cout << "Intern copy constructor" << std::endl;
    *this = other;
}

Intern::~Intern() {
    std::cout << "Intern destructor" << std::endl;
}

Intern &Intern::operator=(const Intern &src) {
    std::cout << "Intern assignation operator" << std::endl;
    if (this != &src)
        *this = src;

    return *this;
}

AForm *Intern::makeForm(
    const std::string &formName, const std::string &target) {
    std::string formNames[3] = {
        "shrubbery creation", "robotomy request", "presidential pardon"};

    AForm *(Intern::*formFunctions[3])(const std::string &target) = {
        &Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm,
        &Intern::makePresidentialPardonForm};

    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            return (this->*formFunctions[i])(target);
        }
    }
    return NULL;
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}
