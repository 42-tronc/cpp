#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main(void) {
    printAction("Using the subject's main");
    IMateriaSource* materia = new MateriaSource();

    materia->learnMateria(new Ice());
    materia->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = materia->createMateria("ice");
    me->equip(tmp);
    tmp = materia->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete materia;

    printAction("Creating a MateriaSource");
    MateriaSource* src = new MateriaSource();

    printAction("Creating Materias");
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());

    printAction("Creating a Character");
    Character* john = new Character("john");

    printAction("Equipping the Character with Materias");
    AMateria* spell;
    spell = src->createMateria("ice");
    john->equip(spell);
    spell = src->createMateria("fuyfyufyiu");
    john->equip(spell);
    spell = src->createMateria("ice");
    john->equip(spell);
    spell = src->createMateria("cure");
    john->equip(spell);
    spell = src->createMateria("ice");
    john->equip(spell);
    spell = src->createMateria("cure");
    john->equip(spell);

    ICharacter* mosh = new Character("mosh");
    john->unequip(0);
    john->unequip(0);
    john->unequip(5);
    for (int i = -1; i < 4; i++) john->use(i, *mosh);
    spell = src->createMateria("cure");
    for (int i = 0; i < 5; i++) john->equip(spell);
    john->use(0, *mosh);

    delete mosh;
    delete john;
    delete src;

    printAction("Exiting the program");

    return 0;
}
