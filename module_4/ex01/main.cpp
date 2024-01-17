#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}
int main(void) {
    const int arraySize = 10;

    printAction("Creating an array of Animals");
    Animal* animals[arraySize];

    printAction("Filling half of the array with Dog objects");
    for (int i = 0; i < arraySize / 2; i++) animals[i] = new Dog();

    printAction("Filling the other half of the array with Cat objects");
    for (int i = arraySize / 2; i < arraySize; i++) animals[i] = new Cat();

    printAction("Printing each type of Animal in the array");
    for (int i = 0; i < arraySize; i++) {
        std::cout << "\e[90m" << i + 1 << ":\e[3;37m " << animals[i]->getType()
                  << "\e[90m\nSound: ";
        animals[i]->makeSound();
    }

    printAction("Deleting the first element of the array (Dog)");
    delete animals[0];

    printAction("Printing the array again");
    for (int i = 0; i < arraySize; i++) {
        std::cout << "\e[90m" << i + 1 << ":\e[3;37m " << animals[i]->getType()
                  << std::endl;
    }

    printAction("Deleting every Animal in the array");
    for (int i = 1; i < arraySize; i++) {
        std::cout << "\e[90m" << i + 1 << ":\e[0m ";
        delete animals[i];
    }

    printAction("Testing the subject's main");
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;  // should not create a leak
    delete i;

    printAction("Exiting the program");

    return 0;
}
