#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}
int main(void) {
    printAction("Creating a Cat, a Dog and an Animal");
    Cat cat;
    Dog dog;
    Animal animal;

    const Animal* animalPtr = new Animal();
    const Animal* dogPtr = new Dog();
    const Animal* catPtr = new Cat();

    printAction("Creating a WrongAnimal and a WrongCat");
    WrongAnimal wrongAnimal;
    const WrongAnimal* wrongAnimalPtr = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    printAction("Creating a copy of Cat");
    Cat catCopy(cat);

    printAction("Creating a copy of Cat with the assignation operator");
    Cat catCopy2 = cat;

    printAction("Creating a copy of Dog");
    Dog dogCopy(dog);

    printAction("Get the type of each animal");
    std::cout << "\e[0mCat type: \e[1;37m" << cat.getType() << std::endl
              << "\e[0mDog type: \e[1;37m" << dog.getType() << std::endl
              << "\e[0mAnimal type: \e[1;37m" << animal.getType() << std::endl
              << "\e[0mWrongAnimal type: \e[1;37m" << wrongAnimal.getType()
              << std::endl
              << "\e[0mWrongCat type: \e[1;37m" << wrongCat->getType()
              << std::endl
              << std::endl
              << "\e[0manimalPtr type: \e[1;37m" << animalPtr->getType()
              << std::endl
              << "\e[0mdogPtr type: \e[1;37m" << dogPtr->getType() << std::endl
              << "\e[0mcatPtr type: \e[1;37m" << catPtr->getType() << std::endl
              << "\e[0mwrongAnimalPtr type: \e[1;37m"
              << wrongAnimalPtr->getType() << std::endl
              << "\e[0mwrongCat type: \e[1;37m" << wrongCat->getType()
              << std::endl;

    printAction("Get the sound of each animal");
    std::cout << "Cat sound: ";
    cat.makeSound();
    std::cout << "Dog sound: ";
    dog.makeSound();
    std::cout << "Animal sound: ";
    animal.makeSound();
    std::cout << "WrongAnimal sound: ";
    wrongAnimal.makeSound();
    std::cout << "WrongCat sound: ";
    wrongCat->makeSound();
    std::cout << std::endl;
    std::cout << "animalPtr sound: ";
    animalPtr->makeSound();
    std::cout << "dogPtr sound: ";
    dogPtr->makeSound();
    std::cout << "catPtr sound: ";
    catPtr->makeSound();
    std::cout << "wrongAnimalPtr sound: ";
    wrongAnimalPtr->makeSound();
    std::cout << "wrongCat sound: ";
    wrongCat->makeSound();

    printAction("Delete all the animals");
    delete wrongCat;
    delete wrongAnimalPtr;
    delete catPtr;
    delete dogPtr;
    delete animalPtr;

    printAction("Exiting the program");

    return 0;
}
