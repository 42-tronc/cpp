#include "AForm.hpp"

/**
 * @brief Print an error message to the console
 *
 * @note We use the inline keyword to avoid multiple definitions of the function
 * It effectively tells the compiler to replace the function call with the
 * function code at compile time
 */
inline void printError(const std::string &str, short grade) {
    std::cerr << "\e[1;31m [ERROR] \e[;3;30m" << str
              << "\n\tResetting grade to " << grade << "\e[0m" << std::endl;
}

AForm::AForm()
    : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    // std::cout << "\e[32m󱪠 AForm (\e[3;37m" << name
    //           << "\e[;32m) was created with grade to sign \e[1;33m"
    //           << gradeToSign << "\e[;32m and grade to execute \e[1;33m"
    //           << gradeToExecute << std::endl;
}

AForm::AForm(const std::string name, short gradeToSign, short gradeToExecute)
    : name(name),
      isSigned(false),
      gradeToSign(checkGrade(gradeToSign)),
      gradeToExecute(checkGrade(gradeToExecute)) {
    // std::cout << "\e[32m󱪠 AForm (\e[3;37m" << this->name
    //           << "\e[;32m) was created with grade to sign \e[1;33m"
    //           << this->gradeToSign << "\e[;32m and grade to execute \e[1;33m"
    //           << this->gradeToExecute << "\e[0m" << std::endl;
}

AForm::AForm(const AForm &other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute) {
    std::cout << "\e[32m󱪠 AForm (\e[3;37m" << name
              << "\e[;32m) was created with grade to sign \e[1;33m"
              << gradeToSign << "\e[;32m and grade to execute \e[1;33m"
              << gradeToExecute << "\e[0m" << std::endl;
}

AForm::~AForm() {
    // std::cout << "\e[31m󱪠 AForm (\e[3;37m" << name
    //           << "\e[;31m) was destroyed\e[0m" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

const std::string &AForm::getName() const {
    return name;
}

const bool &AForm::getIsSigned() const {
    return isSigned;
}

const short &AForm::getGradeToSign() const {
    return gradeToSign;
}

const short &AForm::getGradeToExecute() const {
    return gradeToExecute;
}

short AForm::checkGrade(short grade) const {
    try {
        if (grade < 1)
            throw AForm::GradeTooHighException();
        else if (grade > 150)
            throw AForm::GradeTooLowException();

        return grade;
    } catch (const AForm::GradeTooHighException &ex) {
        printError(ex.what(), 1);
        return 1;
    } catch (const AForm::GradeTooLowException &ex) {
        printError(ex.what(), 150);
        return 150;
    }
}

bool AForm::canExec(const Bureaucrat &executor, short gradeToExecute) const {
    try {
        if (executor.getGrade() > gradeToExecute)
            throw AForm::GradeTooLowException();
        return true;
    } catch (const AForm::GradeTooLowException &ex) {
        std::cerr << "\e[1;31m [ERROR] \e[3;37m" << executor.getName()
                  << "\e[;31m cannot execute \e[3;37m" << name
                  << " \e[;3;30m(\e[1;31m" << executor.getGrade()
                  << "\e[;3;30m/" << gradeToExecute << ")\e[0m" << std::endl;
    }
    return false;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    try {
        if (isSigned) {
            throw AForm::AlreadySignedException();
        }
        if (bureaucrat.getGrade() > gradeToSign)
            throw AForm::GradeTooLowException();
        isSigned = true;
        std::cout << "\e[1;37m" << bureaucrat.getName()
                  << "\e[0m signed the AForm \e[1;33m" << name << "\e[0m"
                  << std::endl;
    } catch (const AForm::GradeTooLowException &ex) {
        std::cerr << "\e[1;37m" << bureaucrat.getName()
                  << "\e[0m cannot sign the AForm \e[1;33m" << name
                  << "\e[0m(\e[1;31m" << bureaucrat.getGrade() << "\e[0m/"
                  << gradeToSign << ")" << std::endl;
    } catch (const AForm::AlreadySignedException &ex) {
        std::cerr << "\e[1;33m" << name << "\e[0m is already signed"
                  << std::endl;
    }
}

void AForm::debugPrint(bool creation) const {
    // std::string color_code = creation ? "\e[32m" : "\e[31m";
    // std::string action = creation ? "created" : "destroyed";
    // std::string icon = creation ? "󱪝" : "󱪠";

    if (creation) {
        std::cout << "\e[32m󱪝 Form (\e[3;37m" << name
                  << "\e[;32m) was created with grade to sign \e[1;33m"
                  << gradeToSign << "\e[;32m and grade to execute \e[1;33m"
                  << gradeToExecute << "\e[0m" << std::endl;
    } else {
        std::cout << "\e[31m󱪠 AForm (\e[3;37m" << name
                  << "\e[;31m) was destroyed\e[0m" << std::endl;
    }
}

std::ostream &operator<<(std::ostream &stream, const AForm &AForm) {
    stream << "\e[1;36m" << AForm.getName() << "\e[0m AForm is "
           << (AForm.getIsSigned() ? "\e[1;32m" : "\e[1;31mnot ")
           << "signed\e[0m (Sign: \e[1;33m" << AForm.getGradeToSign()
           << "\e[0m, Execute: \e[1;33m" << AForm.getGradeToExecute()
           << "\e[0m)";
    return stream;
}
