#include "Serializer.hpp"

void printAction(const std::string& str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

int main(void) {
    printAction("Creating Data object");
    Data data = {42, "John Doe", true};

    printAction("Serializing Data object");
    uintptr_t serialized = Serializer::serialize(&data);

    printAction("Printing serialized Data object");
    std::cout << "\e[1;33mGrade: \e[0m"
              << reinterpret_cast<Data*>(serialized)->grade
              << "\n\e[1;33mName: \e[0m"
              << reinterpret_cast<Data*>(serialized)->name
              << "\n\e[1;33mIs Enrolled: \e[0m"
              << reinterpret_cast<Data*>(serialized)->isEnrolled << std::endl;

    printAction("Deserializing Data object");
    Data* deserialized = Serializer::deserialize(serialized);

    printAction("Printing deserialized Data object");
    std::cout << "\e[1;33mGrade: \e[0m" << deserialized->grade
              << "\n\e[1;33mName: \e[0m" << deserialized->name
              << "\n\e[1;33mIs Enrolled: \e[0m" << deserialized->isEnrolled
              << std::endl;

    return 0;
}
