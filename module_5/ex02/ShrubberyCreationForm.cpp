#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("default") {
    debugPrint();
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {
    debugPrint();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {
    debugPrint();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    debugPrint(false);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
    if (this != &other) {
        target = other.target;
    }
    debugPrint();
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!canExec(executor, getGradeToExecute())) {
        return;
    }

    try {
        std::ofstream outfile((target + "_shrubbery").c_str());
        if (!outfile.is_open()) {
            throw FileNotOpenedException();
        }
        outfile << "ASCII trees" << std::endl;
        if (outfile.bad()) {
            throw FileNotWrittenException();
        }
        std::cout << "\e[3;33m󰔱 Shrubbery for \e[3;37m" << target
                  << "\e[;33m has been created successfully\e[0m" << std::endl;
        outfile.close();
    } catch (const FileNotOpenedException& ex) {
        std::cerr << ex.what() << std::endl;
    } catch (const FileNotWrittenException& ex) {
        std::cerr << ex.what() << std::endl;
    }
}
