#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>

#include "Array.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n" << std::endl;
}

template <typename T>
void printSize(const Array<T>& arr) {
    std::cout << "\e[1;33mSize: \e[0m" << arr.getSize() << std::endl;
}

template <typename T>
void printArray(Array<T>& arr) {
    std::cout << "\e[1;33mArray: \e[0m";
    for (size_t i = 0; i < arr.getSize(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

std::string intToString(int num) {
    std::stringstream ss;
    ss << num;
    return ss.str();
}

#define MAX_VAL 750

int main(int, char**) {
    printAction("Create an array of 10 integers and print its size");
    Array<int> numbers(10);
    printSize(numbers);

    printAction("Fill the array with random numbers and print it");
    srand(time(0));
    for (size_t i = 0; i < numbers.getSize(); i++) {
        numbers[i] = rand() % MAX_VAL;
    }
    printArray(numbers);

    printAction("Create a copy of the array");
    Array<int> copy(numbers);

    printAction("Print the copy");
    printArray(copy);
    printSize(copy);

    printAction("Change and print the copy");
    for (size_t i = 0; i < copy.getSize(); i++) {
        copy[i] = rand() % MAX_VAL;
    }
    printArray(copy);
    printSize(copy);

    printAction("Create a new array, assign the copy to it and print it");
    Array<int> assigned;
    assigned = copy;

    printArray(assigned);
    printSize(assigned);

    printAction("Change and print the assigned array");
    for (size_t i = 0; i < assigned.getSize(); i++) {
        assigned[i] = rand() % MAX_VAL;
    }
    printArray(assigned);

    printAction("Print the original array");
    printArray(numbers);

    printAction("Create a default array with 0 elements and print its size");
    Array<int> empty;
    printSize(empty);

    printAction("Try to access an element of the empty array");
    try {
        std::cout << empty[0] << std::endl;
    } catch (const std::out_of_range& ex) {
        std::cerr << ex.what() << std::endl;
    }

    printAction("Create an array of 5 doubles and print its size");
    Array<double> doubles(5);
    printSize(doubles);

    printAction("Fill the array with random numbers and print it");
    for (size_t i = 0; i < doubles.getSize(); i++) {
        doubles[i] = (rand() % MAX_VAL) / 10.0;
    }
    printArray(doubles);

    printAction("Create an array of 5 strings and print its size");
    Array<std::string> strings(5);
    printSize(strings);

    printAction("Fill the array with random strings and print it");
    for (size_t i = 0; i < strings.getSize(); i++) {
        strings[i] = "string" + intToString(i);
    }
    printArray(strings);

    printAction("Create an array of const ints and print its size");
    const Array<int> constNumbers(5);
    printSize(constNumbers);

    printAction("Try to change an element of the const array");
    try {
        constNumbers[0] = 42;
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
    printArray(constNumbers);

    printAction("Testing with the subject's main.cpp file");
    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++) {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }

        printAction("Print the array and its size");
        printSize(numbers);
        printArray(numbers);

        // SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++) {
            if (mirror[i] != numbers[i]) {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }

        printAction("Try to access an element out of the array's bounds");
        try {
            numbers[-2] = 0;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }

        printAction("Try to access an element out of the array's bounds");
        try {
            numbers[MAX_VAL] = 0;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++) {
            numbers[i] = rand();
        }
        delete[] mirror;  //
    }

    return 0;
}
