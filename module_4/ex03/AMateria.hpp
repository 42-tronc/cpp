#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#include "ICharacter.hpp"

class ICharacter;

class AMateria {
public:
    AMateria();
    AMateria(const std::string& type);
    AMateria(const AMateria& other);
    virtual ~AMateria();

    AMateria& operator=(const AMateria& other);

    std::string const& getType() const;  // Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

protected:
    std::string type;
};

#endif
