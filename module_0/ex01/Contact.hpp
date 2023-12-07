#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <limits>
#include <stdlib.h>

class Contact {
public:
    Contact();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setNickname(const std::string& nickname);
    void setPhoneNumber(const std::string& phoneNumber);
    void setDarkestSecret(const std::string& darkestSecret);

private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};

std::string printAction(std::string str);
std::string printUnderlined(std::string str);
std::string getValidInput(const std::string &prompt);

#endif
