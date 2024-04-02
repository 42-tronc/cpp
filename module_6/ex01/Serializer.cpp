#include "Serializer.hpp"

// Serialize function: Convert pointer to uintptr_t
uintptr_t Serializer::serialize(Data* ptr) {
    std::cout << "Data* serialized" << std::endl;
    return reinterpret_cast<uintptr_t>(ptr);
}

// Deserialize function: Convert uintptr_t to pointer
Data* Serializer::deserialize(uintptr_t raw) {
    std::cout << "Data* deserialized" << std::endl;
    return reinterpret_cast<Data*>(raw);
}

Serializer::~Serializer() {
    std::cout << "Destructor called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    return *this;
}
