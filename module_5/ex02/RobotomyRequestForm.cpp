#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default") {
    debugPrint();
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {
    debugPrint();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {
    debugPrint();
}

RobotomyRequestForm::~RobotomyRequestForm() {
    debugPrint(false);
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
                  << executor.getName() << "\e[;32m has robotomized \e[3;37m"
                  << target << "\e[;32m successfully\e[0m" << std::endl;
    } else {
        std::cout << "\e[33m󰷴 Chk-Chk-chk... Chk-chk-chk......\n"
                  << "\e[31mLooks like the drill stalled..\nSorry \e[3;37m"
                  << executor.getName() << "\e[;31m, but \e[3;37m" << target
                  << "\e[;31m is not robotomized\e[0m" << std::endl;
    }
}
