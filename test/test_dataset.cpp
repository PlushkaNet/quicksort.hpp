#include <iostream>
#include <chrono>

#include "../quicksort.hpp"

#include "../utils/arrdump.hpp"

template <typename T>
bool run_test(T *data, unsigned int len) {
    auto start = std::chrono::high_resolution_clock::now();
    qs::quicksort<T>(data, len);
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "sorting complete in " << (stop-start).count() / 1000000 << " ms (started at: " <<
        start.time_since_epoch().count() << ", ended at: " << stop.time_since_epoch().count() << ")\n";
    return qs::is_sorted(data, len);
}

int main() {
    int *arr; unsigned int size;
    arrdump_utils::undump_t<int, unsigned int>("dump.bin", arr, size);
    run_test<int>(arr, size);
    delete[] arr;
}
