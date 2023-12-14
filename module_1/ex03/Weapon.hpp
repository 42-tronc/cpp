#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon {
public:
    Weapon(std::string type);

    std::string const& getType() const;
    void setType(const std::string& type);

private:
    std::string type;
};

#endif
