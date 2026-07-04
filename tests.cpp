#include <cstdlib>
#include <functional>
#include <iostream>
#include <chrono>

#include "quicksort.hpp"

#include "utils/pretty_utils.hpp"

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
bool run_test(int len, std::function<T(void)> rng) {
    T *data = generate_large_data<T>(len, rng);
    std::cout << "data generated\n";
    bool status = run_test_only<T>(data, len);
    delete[] data;
    return status;
}

int main() {
    enum {ARR_LENGTH = 10000000};

    std::cout << "testing quicksort for 10 million items\n";

    if(!run_test<int>(ARR_LENGTH, rand)) return 1;
    std::cout << "test quicksort for INT passed\n";

    if(!run_test<int>(ARR_LENGTH, mrand48)) return 1;
    std::cout << "test quicksort for SIGNED LONG passed\n";

    if(!run_test<int>(ARR_LENGTH, lrand48)) return 1;
    std::cout << "test quicksort for UNSIGNED LONG passed\n";

    if(!run_test<int>(ARR_LENGTH, drand48)) return 1;
    std::cout << "test quicksort for DOUBLE passed\n";
}
