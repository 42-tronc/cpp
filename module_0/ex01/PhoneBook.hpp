#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook();
    void addContact();
    void searchContact();
private:
    int contactCount;
    Contact contacts[8];
};

#endif
