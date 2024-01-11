#include "Cat.hpp"
#include "Dog.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}
int main(void) {
    printAction("Creating a Cat object and a Dog object");
    Cat cat;
    Dog dog;
    // Animal animal; // not possible because Animal is abstract

    printAction("Creating a copy of Cat");
    Cat catCopy(cat);

    printAction("Creating a copy of Dog");
    Dog dogCopy(dog);

    printAction("Exiting the program");

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();  // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    return 0;
}
