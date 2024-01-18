#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main(void) {
    // printAction("Using the subject's main");
    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // ICharacter* me = new Character("me");
    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // ICharacter* bob = new Character("bob");
    // me->use(0, *bob);
    // me->use(1, *bob);
    // delete bob;
    // delete me;
    // delete src;

    // MateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // src->learnMateria(new Cure());

    // // std::cout << std::endl;

    // Character* me = new Character("me");
    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("fuyfyufyiu");
    // me->equip(tmp);
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);

    // // std::cout << std::endl;

    // ICharacter* bob = new Character("bob");
    // me->unequip(0);
    // me->unequip(0);
    // me->unequip(5);
    // for (int i = -1; i < 4; i++) me->use(i, *bob);
    // tmp = src->createMateria("cure");
    // for (int i = 0; i < 2; i++) me->equip(tmp);
    // me->use(0, *bob);

    // delete bob;
    // delete me;
    // delete src;

    printAction("Creating a MateriaSource");
    IMateriaSource* src = new MateriaSource();

    printAction("Creating a Character");
    ICharacter* me = new Character("John");

    printAction("Equipping the Character with an Ice Materia");
    AMateria* ice = new Ice();
    src->learnMateria(ice);
    me->equip(ice);

    printAction("Equipping the Character with a Cure Materia");
    AMateria* cure = new Cure();
    src->learnMateria(cure);
    me->equip(cure);

    printAction("Creating another Character");
    ICharacter* bob = new Character("Bob");

    printAction("Using the Ice Materia on Bob");
    me->use(0, *bob);

    printAction("Using the Cure Materia on Bob");
    me->use(1, *bob);

    printAction("Unequipping the already used Ice Materia");
    me->unequip(0);

    printAction("Creating multiple Materia");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("fire");
    me->equip(tmp);
    tmp = src->createMateria("water");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    printAction("Using the Ice Materia on Bob");
    // me->use(0, *bob);

    printAction("Exiting the program");
    delete me;
    delete bob;
    delete src;

    return 0;
}
