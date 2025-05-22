/**
 * @file invalidFree.cpp
 * @brief
 * Do not free the resource which dose not need you to manage
 */
#include <iostream>

int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; i += 1) {
        printf("[%d] => %s\n", i, argv[i]);
    }

    // Invalid free
    for (int i = 0; i < argc; i += 1) {
        free(argv[i]);
    }

    for (int i = 0; i < argc; i += 1) {
        printf("[%d] => %s\n", i, argv[i]);
    }
}