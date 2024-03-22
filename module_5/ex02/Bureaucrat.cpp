#include "Bureaucrat.hpp"

inline void printError(const std::string& str, short grade) {
    std::cerr << "\e[1;31m [ERROR] \e[0;3;30m" << str
              << "\n\tResetting grade to " << grade << "\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
    std::cout << "\e[32mBureaucrat \e[3;30m" << name
              << "\e[0m was created with grade " << this->grade << "\e[0m"
              << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, short grade) : name(name) {
    setGrade(grade);
    std::cout << "\e[32mBureaucrat (\e[3;37m" << this->name
              << "\e[;32m) was created with grade \e[1;33m" << this->grade
              << "\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name), grade(other.grade) {
    std::cout << "\e[32mBureaucrat (\e[3;37m" << name
              << "\e[32m) was created with grade \e[1;33m" << grade << "\e[0m"
              << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "\e[31mBureaucrat (\e[3;37m" << name
              << "\e[31m) was destroyed\e[0m" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        grade = other.grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const {
    return name;
}

const short& Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::setGrade(short grade) {
    try {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();

        this->grade = grade;
    } catch (const Bureaucrat::GradeTooHighException& ex) {
        printError(ex.what(), 1);
        this->grade = 1;
    } catch (const Bureaucrat::GradeTooLowException& ex) {
        printError(ex.what(), 150);
        this->grade = 150;
    }
}

void Bureaucrat::incrementGrade() {
    short oldGrade = grade;
    setGrade(grade - 1);
    if (grade != oldGrade)
        std::cout << "\e[1;37m" << name
                  << "\e[0m's grade was incremented to \e[1;33m" << grade
                  << "\e[0m" << std::endl;
    else
        std::cout << "\e[1;37m" << name
                  << "\e[0m's grade is already at the highest possible value"
                  << std::endl;
}

void Bureaucrat::decrementGrade() {
    short oldGrade = grade;
    setGrade(grade + 1);
    if (grade != oldGrade)
        std::cout << "\e[1;37m" << name
                  << "\e[0m's grade was decremented to \e[1;33m" << grade
                  << "\e[0m" << std::endl;
    else
        std::cout << "\e[1;37m" << name
                  << "\e[0m's grade is already at the lowest possible value"
                  << std::endl;
}

void Bureaucrat::signAForm(AForm& AForm) {
    AForm.beSigned(*this);
}

void Bureaucrat::executeAForm(const AForm& AForm) const {
    AForm.execute(*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade cannot be higher than 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade cannot be lower than 150";
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat) {
    std::cout << "\e[1;37m" << bureaucrat.getName() << "\e[0m has a grade of "
              << "\e[1;33m" << bureaucrat.getGrade() << "\e[0m";
    return stream;
}
