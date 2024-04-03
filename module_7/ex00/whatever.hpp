#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T first, T second) {
    return first > second ? second : first;
}

template <typename T>
T max(T first, T second) {
    return first > second ? first : second;
}

#endif
