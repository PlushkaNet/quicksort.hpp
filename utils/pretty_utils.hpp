#include <functional>
#include <iostream>

template <typename T>
void print_arr(T *arr, unsigned int len) {
    unsigned int last_index = len-1;
    for(unsigned int i = 0; i < len; i++) {
        std::cout << arr[i];
        if(i != last_index) std::cout << ", ";
    }
    std::cout << std::endl;
}

template <typename T>
T *generate_large_data(unsigned int len, std::function<T(void)> rng) {
    T *arr = new T[len];
    for(unsigned int i = 0; i < len; i++) {
        arr[i] = rng();
    }
    return arr;
}
