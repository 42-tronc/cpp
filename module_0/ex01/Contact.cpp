#include "Contact.hpp"

Contact::Contact() {
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return std::string();
}

void Contact::setFirstName(const std::string &firstName) {
    this->firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void Contact::setNickname(const std::string& nickname) {
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
    this->darkestSecret = darkestSecret;
}

std::string printUnderlined(std::string str) {
    return "\033[4m" + str + "\033[0m";
}

std::string printAction(std::string str) {
    return "\ec\e[1;33m* \e[21m\e[34m" + str + "\e[0m\n\n";
}

std::string getValidInput(const std::string &prompt) {
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
            std::exit(0);
        else if (!input.empty())
            break;
        else if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return input;
}
