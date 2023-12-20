#include <iostream>
#include <limits>
#include <stdlib.h>
#include "PhoneBook.hpp"

// void addContact(PhoneBook &phoneBook)

int main(void) {
    PhoneBook phoneBook;

    std::cout << printAction("WELCOME TO THE PHONEBOOK")
              << "\e[90;3mWhat would you like to do?\e[0m\n"
              << printUnderlined("ADD") << " a contact\n"
              << printUnderlined("SEARCH") << " for a contact\n"
              << printUnderlined("EXIT") << " the PhoneBook\n";

    while (true) {
        std::string input = getValidInput("\n\e[90mChoice: \e[0m");
        if (input.empty()) break;

        if (input == "EXIT")
            break;
        else if (input == "ADD")
            phoneBook.addContact();
        else if (input == "SEARCH")
            phoneBook.searchContact();
    }
    return 0;
}
