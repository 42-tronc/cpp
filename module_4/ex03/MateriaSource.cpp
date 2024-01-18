#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    *this = other;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        if (memory[i]) {
            delete memory[i];
            memory[i] = NULL;
        }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        //     for (int i = 0; i < count; i++) delete memory[i];

        //     count = other.count;
        //     for (int i = 0; i < count; i++) memory[i] =
        //     other.memory[i]->clone();
        // }
        for (int i = 0; i < 4; i++) {
            if (this->memory[i]) {
                delete this->memory[i];
                this->memory[i] = NULL;
            }
            if (other.memory[i])
                this->memory[i] = other.memory[i]->clone();
            else
                this->memory[i] = NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
    if (!materia) {
        std::cout << "MateriaSource: materia is NULL" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
        if (!memory[i]) {
            memory[i] = materia;
            return;
        }
    std::cout << "MateriaSource: memory is full" << std::endl;
    delete materia;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    for (int i = 0; i < 4; i++)
        if (memory[i]->getType() == type) return memory[i]->clone();
    return NULL;
}
