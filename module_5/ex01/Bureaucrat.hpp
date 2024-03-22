#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

#include "Form.hpp"

class Form;

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

    void signForm(Form &form);

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
