#include "Form.hpp"

/**
 * @brief Print an error message to the console
 *
 * @note We use the inline keyword to avoid multiple definitions of the function
 * It effectively tells the compiler to replace the function call with the
 * function code at compile time
 */
inline void printError(const std::string &str, short grade) {
    std::cerr << "\e[1;31m[ERROR] \e[;3;30m" << str << "\n\tResetting grade to "
              << grade << "\e[0m" << std::endl;
}

Form::Form()
    : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "\e[32mForm (\e[3;37m" << name
              << "\e[;32m) was created with grade to sign \e[1;33m"
              << gradeToSign << "\e[;32m and grade to execute \e[1;33m"
              << gradeToExecute << std::endl;
}

Form::Form(const std::string name, short gradeToSign, short gradeToExecute)
    : name(name),
      isSigned(false),
      gradeToSign(checkGrade(gradeToSign)),
      gradeToExecute(checkGrade(gradeToExecute)) {
    std::cout << "\e[32mForm (\e[3;37m" << this->name
              << "\e[;32m) was created with grade to sign \e[1;33m"
              << this->gradeToSign << "\e[;32m and grade to execute \e[1;33m"
              << this->gradeToExecute << "\e[0m" << std::endl;
}

Form::Form(const Form &other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute) {
    std::cout << "\e[32mForm (\e[3;37m" << name
              << "\e[;32m) was created with grade to sign \e[1;33m"
              << gradeToSign << "\e[;32m and grade to execute \e[1;33m"
              << gradeToExecute << "\e[0m" << std::endl;
}

Form::~Form() {
    std::cout << "\e[31mForm (\e[3;37m" << name << "\e[;31m) was destroyed\e[0m"
              << std::endl;
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

const std::string &Form::getName() const {
    return name;
}

const bool &Form::getIsSigned() const {
    return isSigned;
}

const short &Form::getGradeToSign() const {
    return gradeToSign;
}

const short &Form::getGradeToExecute() const {
    return gradeToExecute;
}

short Form::checkGrade(short grade) {
    try {
        if (grade < 1)
            throw Form::GradeTooHighException();
        else if (grade > 150)
            throw Form::GradeTooLowException();

        return grade;
    } catch (const Form::GradeTooHighException &ex) {
        printError(ex.what(), 1);
        return 1;
    } catch (const Form::GradeTooLowException &ex) {
        printError(ex.what(), 150);
        return 150;
    }
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    try {
        if (bureaucrat.getGrade() > gradeToSign)
            throw Form::GradeTooLowException();
        isSigned = true;
        std::cout << "\e[1;33m" << bureaucrat.getName()
                  << "\e[0m signed the form \e[1;33m" << name << "\e[0m"
                  << std::endl;
    } catch (const Form::GradeTooLowException &ex) {
        std::cerr << "\e[1;31m[ERROR] \e[;3;30m" << ex.what()
                  << "\e[0m: \e[1;33m" << bureaucrat.getName()
                  << "\e[0m cannot sign the form \e[1;33m" << name << "\e[0m"
                  << std::endl;
    }
}
