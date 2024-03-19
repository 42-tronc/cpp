#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default") {
    std::cout << "\e[32m󱪞 RobotomyRequestForm (\e[3;37m" << getName()
              << "\e[;32m) was created with grade to sign \e[1;33m"
              << getGradeToSign() << "\e[;32m and grade to execute \e[1;33m"
              << getGradeToExecute() << "\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {
    std::cout << "\e[32m󱪞 RobotomyRequestForm (\e[3;37m" << getName()
              << "\e[;32m) was created with grade to sign \e[1;33m"
              << getGradeToSign() << "\e[;32m and grade to execute \e[1;33m"
              << getGradeToExecute() << "\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {
    std::cout << "\e[32m󱪞 RobotomyRequestForm (\e[3;37m" << getName()
              << "\e[;32m) was created with grade to sign \e[1;33m"
              << getGradeToSign() << "\e[;32m and grade to execute \e[1;33m"
              << getGradeToExecute() << "\e[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "\e[31m󱪠 RobotomyRequestForm (\e[3;37m" << getName()
              << "\e[;31m) was destroyed\e[0m" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
    if (this != &other) {
        target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!canExec(executor, getGradeToExecute())) {
        return;
    }

    std::srand(std::time(0));  // use current time as seed for random generator
    if (std::rand() % 2) {  // if random number is even
        std::cout << "\e[3;33m󰷴 Whirrrrr... Whirrrrr...\tVrrrrrr... "
                     "Vrrrrrr...\n\e[3;37m"
                  << target << "\e[;32m has been robotomized successfully\e[0m"
                  << std::endl;
    } else {
        std::cout << "\e[33m󰷴 Chk-Chk-chk... Chk-chk-chk......\n"
                  << "Looks like \e[3;37m" << executor.getName()
                  << "\e[;33m failed to robotomize " << target << "\e[0m"
                  << std::endl;
    }
}
