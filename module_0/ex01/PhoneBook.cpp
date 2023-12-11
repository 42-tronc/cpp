#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), contactCount(0) {
}

void PhoneBook::addContact() {
    std::cout << printAction("ADDING A NEW CONTACT");

    if (contactCount == 8)
        std::cout << "\e[31mPhoneBook is full\e[0m\nOverwriting the oldest contact\n\n";
    else
        contactCount++;

    contacts[index].setFirstName(getValidInput("Enter first name: "));
    contacts[index].setLastName(getValidInput("Enter last name: "));
    contacts[index].setNickname(getValidInput("Enter nickname: "));
    contacts[index].setPhoneNumber(getValidInput("Enter phone number: "));
    contacts[index].setDarkestSecret(getValidInput("Enter darkest secret: "));
    index < 7 ? index++ : index = 0;

    std::cout << "\e[32mContact added successfully\e[0m\n\n";
}

std::string truncStr(const std::string& input, size_t width) {
    if (input.length() > width)
        return input.substr(0, width - 1) + ".";
    return input;
}

bool isNumber(const std::string& input) {
    for (std::size_t i = 0; i < input.length(); i++) {
        if (!std::isdigit(input[i]))
            return false;
    }
    return true;
}

void PhoneBook::searchContact() {
    std::cout << printAction("SEARCHING A CONTACT");
    const size_t columnWidth = 10;

    if (contactCount == 0) {
        std::cout << "\e[31mPhoneBook is empty\e[0m\n\n";
        return;
    }
    std::cout << std::setw(columnWidth) << "Index" << "|"
              << std::setw(columnWidth) << "First name" << "|"
              << std::setw(columnWidth) << "Last name" << "|"
              << std::setw(columnWidth) << "Nickname" << "\n";

    for (int i = 0; i < contactCount; i++) {
        std::cout << std::setw(columnWidth) << i << "|"
                  << std::setw(columnWidth) << truncStr(contacts[i].getFirstName(), columnWidth) << "|"
                  << std::setw(columnWidth) << truncStr(contacts[i].getLastName(), columnWidth) << "|"
                  << std::setw(columnWidth) << truncStr(contacts[i].getNickname(), columnWidth) << "\n";
    }

    std::string input = getValidInput("Enter an index: ");
    if (!isNumber(input)) {
        std::cout << "Index must be a number\n";
        return;
    }
    int index = std::atoi(input.c_str());

    if (index < 0 || index >= contactCount)
        std::cout << "Index is out of range\n";
    else {
        std::cout << "\e[1mFirst name: \e[0m" << contacts[index].getFirstName() << "\n"
                << "\e[1mLast name: \e[0m" << contacts[index].getLastName() << "\n"
                << "\e[1mNickname: \e[0m" << contacts[index].getNickname() << "\n"
                << "\e[1mPhone number: \e[0m" << contacts[index].getPhoneNumber() << "\n"
                << "\e[1mDarkest secret: \e[0m" << contacts[index].getDarkestSecret() << "\n\n";
    }
}
