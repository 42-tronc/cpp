#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
public:
    Array() : array(new T[0]), size(0) {}
    Array(size_t n) : array(new T[n]), size(n) {}
    Array(const Array& other) : array(new T[other.size]), size(other.size) {
        for (size_t i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
    }
    ~Array() {
        delete[] array;
        size = 0;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] array;
            array = new T[other.size];
            size = other.size;
            for (size_t i = 0; i < size; i++) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }
    T& operator[](const size_t i) const {
        if (i >= size)
            throw std::out_of_range("\e[1;31mIndex out of range\e[0m");
        return array[i];
    }

    size_t getSize() const {
        return size;
    }

private:
    T* array;
    size_t size;
};

#endif
