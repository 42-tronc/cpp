#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    void execute(const Bureaucrat &executor) const;

    class FileNotOpenedException : public std::exception {
    public:
        const char *what() const throw() {
            return "File could not be opened";
        }
    };

    class FileNotWrittenException : public std::exception {
    public:
        const char *what() const throw() {
            return "File could not be written";
        }
    };

private:
    std::string target;
};

#endif
