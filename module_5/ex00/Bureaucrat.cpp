#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
    std::cout << "\e[32mBureaucrat " << name << " was created\e[0m"
              << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, short grade) : name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException(
            "Grade cannot be higher than 1");
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException(
            "Grade cannot be lower than 150");
}
