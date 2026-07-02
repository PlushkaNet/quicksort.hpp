#include <cstdlib>
#include <iostream>
#include <chrono>

#include "quicksort.hpp"

template <typename T>
T *generate_large_data(int len) {
    T *arr = new T[len];
    for(int i = 0; i < len; i++) {
        arr[i] = std::rand();
    }
    return arr;
}

template <typename T>
bool run_test_only(T *data, int len) {
    auto start = std::chrono::high_resolution_clock::now();
    qs::quicksort<T>(data, len);
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "sorting complete in " << (stop-start).count() / 1000000 << " ms (started at: " <<
        start.time_since_epoch().count() << ", ended at: " << stop.time_since_epoch().count() << ")\n";
    return qs::is_sorted(data, len);
}

template <typename T>
bool run_test(int len) {
    T *data = generate_large_data<T>(len);
    std::cout << "data generated\n";
    bool status = run_test_only<T>(data, len);
    delete[] data;
    return status;
}

int main() {
    enum {ARR_LENGTH = 10000000};
    std::cout << "testing quicksort for 10 million items\n";
    if(!run_test<int>(ARR_LENGTH)) return 1;
    std::cout << "test quicksort_i_s passed\n";
}
