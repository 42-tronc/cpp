#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

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

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const
            throw() {  // throw() is only for c++98 (tells the compiler that the
                       // function will not throw any exceptions)
            return "Grade cannot be higher than 1";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw() {
            return "Grade cannot be lower than 150";
        }
    };

private:
    const std::string name;
    short grade;
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);

#endif
