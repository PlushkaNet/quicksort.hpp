#include <cassert>
#include <type_traits>
#include <limits>
#include <ios>
#include <fstream>

namespace arrdump_utils {
    template <typename T, typename UnsignedIntSize>
    bool undump_t(const char *filename, T *&arr, UnsignedIntSize &size) { // -> status
        static_assert(std::is_integral_v<UnsignedIntSize>, "UnsignedIntSize must be integer");
        static_assert(std::is_unsigned_v<UnsignedIntSize>, "UnsignedIntSize must be unsigned");
        static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable");

        std::ifstream file(filename, std::ios::binary);
        if(!file) return false;

        file.read(reinterpret_cast<char *>(&size), sizeof(UnsignedIntSize));
        if (
            !file || (size > (std::numeric_limits<std::streamsize>::max() / sizeof(T)))
        ) return false;

        arr = new T[size];
        file.read(reinterpret_cast<char *>(arr), sizeof(T)*size);
        file.close();

        return file.good();
    }

    template <typename T, typename UnsignedIntSize>
    bool dumparray_t(const char *filename, T *arr, UnsignedIntSize size) { // -> status
        static_assert(std::is_integral_v<UnsignedIntSize>, "UnsignedIntSize must be integer");
        static_assert(std::is_unsigned_v<UnsignedIntSize>, "UnsignedIntSize must be unsigned");
        static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable");

        if(
            arr == nullptr || size > (std::numeric_limits<std::streamsize>::max() / sizeof(T))
        ) return false;

        std::ofstream file(filename, std::ios::binary);
        if(!file) return false;

        file.write(reinterpret_cast<const char *>(&size), sizeof(UnsignedIntSize));
        file.write(reinterpret_cast<const char *>(arr), sizeof(T)*(size));
        file.close();

        return file.good();
    }
}
