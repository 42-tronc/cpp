#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPPPP

#include <cstdlib>  // std::rand
#include <ctime>  // std::time

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    void execute(const Bureaucrat &executor) const;

private:
    std::string target;
};

#endif
