#include "Intern.hpp"

void printAction(const std::string &str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main() {
    // printAction("Create an Intern");
    // Intern intern;
    // AForm* shrub;
    // AForm* robot;
    // AForm* pres;

    // printAction("Create a Shrubbery Creation AForm");
    // shrub = intern.makeForm("shrubbery creation", "home");

    // printAction("Create a Robotomy Request AForm");
    // robot = intern.makeForm("robotomy request", "home");

    // printAction("Create a Presidential Pardon AForm");
    // pres = intern.makeForm("presidential pardon", "home");

    // printAction("Delete the forms");
    // delete shrub;
    // delete robot;
    // delete pres;

    /* std::cout << std::endl
              << std::endl
              << "\033[1m\033[32m"
              << "TESTS EX03 - Testing Intern"
              << "\033[0m" << std::endl;
    std::string name = "invalid name";
    printAction("Creating intern");
    Intern someRandomIntern;

    printAction("Using intern to create AForm, invalid name");
    AForm* invalidForm = someRandomIntern.makeForm("invalid name", "Target");

    printAction("Displaying form stats");
    std::cout << invalidForm << std::endl;

    printAction("Using intern to create AForm, Shrubbery");
    AForm* shrubberyForm =
        someRandomIntern.makeForm("shrubbery creation", "Target");

    printAction("Displaying Shrubbery stats");
    std::cout << *shrubberyForm << std::endl;

    printAction("Using intern to create AForm, Robotomy");
    AForm* robotomyForm =
        someRandomIntern.makeForm("robotomy request", "Target");

    printAction("Displaying Robotomy stats");
    std::cout << *robotomyForm << std::endl;

    printAction("Using intern to create AForm, Presidential");
    AForm* presidentialForm =
        someRandomIntern.makeForm("presidential pardon", "Target");

    printAction("Displaying Presidential stats");
    std::cout << *presidentialForm << std::endl;

    printAction("Creating Bureaucrat");
    Bureaucrat memberLow("MemberLow", 150);
    Bureaucrat memberHigh("MemberHigh", 1);

    printAction("memberLow trying to sign all form");
    memberLow.executeAForm(*shrubberyForm);
    memberLow.executeAForm(*robotomyForm);
    memberLow.executeAForm(*presidentialForm);

    printAction("memberHigh signing all form");
    memberHigh.signAForm(*shrubberyForm);
    memberHigh.signAForm(*robotomyForm);
    memberHigh.signAForm(*presidentialForm);

    printAction("memberLow trying to sign again");
    memberLow.executeAForm(*shrubberyForm);
    memberLow.executeAForm(*robotomyForm);
    memberLow.executeAForm(*presidentialForm);

    printAction("memberHigh execute shrubberyForm");
    memberHigh.executeAForm(*shrubberyForm);

    printAction("memberHigh execute robotomyForm");
    memberHigh.executeAForm(*robotomyForm);

    printAction("memberHigh execute presidentialForm");
    memberHigh.executeAForm(*presidentialForm);

    printAction("Deleting all");
    delete invalidForm;
    delete shrubberyForm;
    delete robotomyForm;
    delete presidentialForm */
    ;

    Intern slave;
    AForm *scf;
    AForm *rrf;
    AForm *ppf;

    try {
        scf = slave.makeForm("shrubbery creation", "Forest");
        rrf = slave.makeForm("robotomy request", "Bender");
        ppf = slave.makeForm("presidential pardon", "PresPard");
        // AForm *wrong;
        // wrong = slave.makeForm("Shrubbery creation", "Dedge");
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        delete scf;
        delete rrf;
        delete ppf;
        return 1;
    }

    {
        printAction("RobotoMyRequestForm");
        Bureaucrat thomas("Thomas", 5);
        thomas.signAForm(*scf);
        thomas.executeAForm(*scf);
        Bureaucrat mehdi("Mehdi", 145);
        mehdi.signAForm(*scf);
        mehdi.executeAForm(*scf);
        Bureaucrat clement("Clement", 150);
        clement.signAForm(*scf);
        clement.executeAForm(*scf);
    }
    {
        printAction("ShrubberyCreationForm");
        Bureaucrat thomas("Thomas", 5);
        thomas.signAForm(*rrf);
        thomas.executeAForm(*rrf);
        Bureaucrat mehdi("Mehdi", 72);
        mehdi.signAForm(*rrf);
        mehdi.executeAForm(*rrf);
        Bureaucrat clement("Clement", 150);
        clement.signAForm(*rrf);
        clement.executeAForm(*rrf);
    }
    {
        printAction("PresidentialPardonForm");
        Bureaucrat thomas("Thomas", 5);
        thomas.signAForm(*ppf);
        thomas.executeAForm(*ppf);
        Bureaucrat mehdi("Mehdi", 25);
        mehdi.signAForm(*ppf);
        mehdi.executeAForm(*ppf);
        Bureaucrat clement("Clement", 150);
        clement.signAForm(*ppf);
        clement.executeAForm(*ppf);
    }

    delete scf;
    delete rrf;
    delete ppf;

    printAction("Exiting the program");

    return 0;
}
