#ifndef FORM_H
#define FORM_H

#include <iostream>

#include "Bureaucrat.hpp"

// Forward declaration of Bureaucrat
class Bureaucrat;

class Form {
public:
    Form();
    Form(const std::string name, short gradeToSign, short gradeToExecute);
    Form(const Form &other);
    ~Form();

    Form &operator=(const Form &other);

    const std::string &getName() const;
    const bool &getIsSigned() const;
    const short &getGradeToSign() const;
    const short &getGradeToExecute() const;

    short checkGrade(short grade);
    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw() {
            return "Grade cannot be higher than 1";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw() {
            return "Grade cannot be lower than 150";
        }
    };

    class AlreadySignedException : public std::exception {
    public:
        const char *what() const throw() {
            return "Form is already signed";
        }
    };

private:
    const std::string name;
    bool isSigned;
    const short gradeToSign;
    const short gradeToExecute;
};

std::ostream &operator<<(std::ostream &stream, const Form &form);

#endif
