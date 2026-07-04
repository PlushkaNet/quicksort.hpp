// creates platform-specific array on hard drive with 1 billion items
#include <cstdlib>
#include "../utils/arrdump.hpp"
#include "../utils/pretty_utils.hpp"

int main() {
    const unsigned int ARR_LENGTH = 1000000000; // 1 billion
    int *arr = generate_large_data<int>(ARR_LENGTH, rand);
    arrdump_utils::dumparray_t("dump.bin", arr, ARR_LENGTH);
    delete[] arr;
}
