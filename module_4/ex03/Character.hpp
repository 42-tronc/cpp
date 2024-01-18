#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
public:
    Character();
    Character(const std::string name);
    Character(const Character& other);
    ~Character();

    Character& operator=(const Character& other);

    void setName(std::string name);
    virtual std::string const& getName() const;

    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

private:
    std::string name;
    AMateria* inventory[4];
    AMateria* floor;
};

#endif
