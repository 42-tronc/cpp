#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5) {
    debugPrint();
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {
    debugPrint();
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm(other), target(other.target) {
    debugPrint();
}

PresidentialPardonForm::~PresidentialPardonForm() {
    debugPrint(false);
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
              << "\e[;33m has been pardoned by the \e[1;35mGreat Zaphod "
                 "Beeblebrox\e[0m"
              << std::endl;
}
