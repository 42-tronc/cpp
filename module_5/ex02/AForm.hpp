#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>

#include "Bureaucrat.hpp"

// Forward declaration of Bureaucrat
class Bureaucrat;

class AForm {
public:
    AForm();
    AForm(const std::string name, short gradeToSign, short gradeToExecute);
    AForm(const AForm &other);
    ~AForm();

    AForm &operator=(const AForm &other);

    const std::string &getName() const;
    const bool &getIsSigned() const;
    const short &getGradeToSign() const;
    const short &getGradeToExecute() const;

    short checkGrade(short grade) const;
    bool canExec(const Bureaucrat &executor, short gradeToExecute) const;
    virtual void execute(const Bureaucrat &executor) const = 0;

    void beSigned(const Bureaucrat &bureaucrat);

    void debugPrint(bool creation = true) const;

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

    class FormNotSigned : public std::exception {
    public:
        const char *what() const throw() {
            return "Form is not signed";
        }
    };

private:
    const std::string name;
    bool isSigned;
    const short gradeToSign;
    const short gradeToExecute;
};

std::ostream &operator<<(std::ostream &stream, const AForm &AForm);

#endif
