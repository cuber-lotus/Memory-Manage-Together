/**
 * P.S. Pay attention to big-endian and little-endian problems.
 */
#include <cstdint>
#include <iostream>

void write(uint8_t* byte, uint32_t u32) {
    *(uint32_t*)byte = u32;
}

void read(uint8_t* byte) {
    // access matching
    std::cout << *(uint32_t*)byte << std::endl;
    // access violation
    std::cout << *(uint64_t*)byte << std::endl;
}

int main() {
    constexpr size_t LEN = sizeof(uint32_t) / sizeof(uint8_t);
    uint8_t          str[LEN];

    write(str, 114514);
    read(str);
}