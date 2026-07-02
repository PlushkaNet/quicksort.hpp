#include <iostream>
#include "quicksort.hpp"

template <typename T>
void print_arr(T *arr, int len) {
    int last_index = len-1;
    for(int i = 0; i < len; i++) {
        std::cout << arr[i];
        if(i != last_index) std::cout << ", ";
    }
    std::cout << std::endl;
}

int main() {
    const int ARR_LEN = 5;
    int arr[ARR_LEN] = {8, 1, 3, 5, 1};
    std::cout << "Unsorted array: \n";
    print_arr(arr, ARR_LEN);
    qs::quicksort(arr, ARR_LEN);
    std::cout << "Sorted array: \n";
    print_arr(arr, ARR_LEN);
    if(qs::is_sorted(arr, ARR_LEN))
        std::cout << "Array sorted sucessfully";
    else
        std::cout << "Array was not sorted";
    std::cout << std::endl;
}
