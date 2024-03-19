#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5) {
    std::cout << "\e[32m� PresidentialPardonForm (\e[3;37m" << getName()
              << "\e[;32m) was created with grade to sign \e[1;33m"
              << getGradeToSign() << "\e[;32m and grade to execute \e[1;33m"
              << getGradeToExecute() << "\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {
    std::cout << "\e[32m� PresidentialPardonForm (\e[3;37m" << getName()
              << "\e[;32m) was created with grade to sign \e[1;33m"
              << getGradeToSign() << "\e[;32m and grade to execute \e[1;33m"
              << getGradeToExecute() << "\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm(other), target(other.target) {
    std::cout << "\e[32m� PresidentialPardonForm (\e[3;37m" << getName()
              << "\e[;32m) was created with grade to sign \e[1;33m"
              << getGradeToSign() << "\e[;32m and grade to execute \e[1;33m"
              << getGradeToExecute() << "\e[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "\e[31m󱪠 PresidentialPardonForm (\e[3;37m" << getName()
              << "\e[;31m) was destroyed\e[0m" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other) {
    if (this != &other) {
        target = other.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!canExec(executor, getGradeToExecute())) {
        return;
    }

    std::cout << "\e[33m \e[3;37m" << target
              << "\e[;3;33m has been pardoned by the \e[1;35mGreat Zaphod "
                 "Beeblebrox\e[0m"
              << std::endl;
}
