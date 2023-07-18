/**
 * @file polymorphism_memoryTruncation.cpp
 * @brief
 *  Memory truncation
 */
#include <iostream>
#define ARR_LENGTH 5

struct Base {
    int32_t x = 11111;
};

struct Derive : Base {
    int32_t y = 22222;
};

/**
 * {Base's pointer offset size} <= {Derive's pointer offset size}
 */
void show(Base arr[]) {
    std::cout << __func__ << std::endl;
    for (int i = 0; i < ARR_LENGTH; i += 1) {
        printf("[%d] = %d\n", i, arr[i].x);
    }
}

int main() {
    Derive arr[ARR_LENGTH];

    std::cout << __func__ << std::endl;
    for (int i = 0; i < ARR_LENGTH; i += 1) {
        printf("[%d] = %d\n", i, arr[i].x);
    }

    show(arr);
}