#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook();
    void addContact();
    void searchContact();
private:
    short index;
    short contactCount;
    Contact contacts[8];
};

#endif
