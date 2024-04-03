#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T, typename U>
void swap(T &a, U &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

#endif
