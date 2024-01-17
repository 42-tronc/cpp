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
    // Animal animal;  // not possible as Animal is an abstract class

    printAction("Creating a WrongAnimal and a WrongCat");
    // WrongAnimal wrongAnimal;  // same as Animal
    WrongCat wrongCat;

    printAction("Creating a copy of Cat");
    Cat catCopy(cat);

    printAction("Creating a copy of Cat with the assignation operator");
    Cat catCopy2 = cat;

    printAction("Creating a copy of Dog");
    Dog dogCopy(dog);

    printAction("Get the type of each animal");
    std::cout << "\e[0mCat type: \e[1;37m" << cat.getType() << std::endl
              << "\e[0mDog type: \e[1;37m" << dog.getType() << std::endl
              << "\e[0mWrongCat type: \e[1;37m" << wrongCat.getType()
              << std::endl;

    printAction("Get the sound of each animal");
    std::cout << "Cat sound: ";
    cat.makeSound();
    std::cout << "Dog sound: ";
    dog.makeSound();
    std::cout << "WrongAnimal sound: ";
    wrongCat.makeSound();

    printAction("Exiting the program");

    return 0;
}
