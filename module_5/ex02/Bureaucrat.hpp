#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

#include "AForm.hpp"

class AForm;

class Bureaucrat {
public:
    Bureaucrat();
    Bureaucrat(const std::string name, short grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &other);

    const std::string &getName() const;
    const short &getGrade() const;
    void setGrade(short grade);

    void incrementGrade();
    void decrementGrade();

    void signAForm(AForm &AForm);
    void executeAForm(const AForm &AForm) const;

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

private:
    const std::string name;
    short grade;
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);

#endif
