#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

class Serializer {
public:
    uintptr_t serialize(Data* ptr);  // convert Data pointer to unsigned integer
    Data* deserialize(uintptr_t raw);  // convert unsigned int to Data pointer

private:
    Serializer();
    Serializer(const Serializer& other);
    ~Serializer();
    Serializer& operator=(const Serializer& other);
};

#endif
