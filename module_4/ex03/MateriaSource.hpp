#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    ~MateriaSource();

    MateriaSource& operator=(const MateriaSource& other);

    virtual void learnMateria(AMateria* materia);
    virtual AMateria* createMateria(std::string const& type);

private:
    AMateria* memory[4];
};

#endif
