#include "Bureaucrat.hpp"
#include "Form.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main() {
    printAction("Create the default Form");
    Form defaultForm;

    printAction("Create a Form with a grade to sign and execute");
    Form fakePassport("Fake Passport", 100, 100);

    printAction("Create a Form with a grade to sign too high");
    Form signTooHigh("Grade Sign Too High", 0, 100);

    printAction("Create a Form with a grade to sign too low");
    Form signTooLow("Grade Sign Too Low", 100, 151);

    printAction("Create a Form with a grade to execute too high");
    Form execTooHigh("Grade Execute Too High", 100, 0);

    printAction("Create a Form with a grade to execute too low");
    Form execTooLow("Grade Execute Too Low", 100, 151);

    printAction(
        "Create a Bureaucrat with just enough grade to sign and execute Fake "
        "Passport");
    Bureaucrat michel("Michel", 100);

    printAction(
        "Create a Bureaucrat with a grade too low to sign Fake Passport");
    Bureaucrat albert("Albert", 101);

    printAction(
        "Create a Bureaucrat with a grade way higher than needed to sign Fake "
        "Passport");
    Bureaucrat jean("Jean", 50);

    printAction("Copying the Fake Passport form");
    Form fakePassportCopy(fakePassport);

    printAction("Print Michel and the Fake Passport");
    std::cout << michel << "\n" << fakePassport << std::endl;

    printAction("Michel tries to sign the Fake Passport");
    michel.signForm(fakePassport);
    std::cout << fakePassport << std::endl;

    printAction("Albert tries to sign the Fake Passport");
    albert.signForm(fakePassport);

    printAction("Jean tries to sign the Fake Passport");
    jean.signForm(fakePassport);

    printAction("Exiting the program");

    return 0;
}
