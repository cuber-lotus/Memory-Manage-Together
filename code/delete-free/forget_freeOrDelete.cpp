#include <stdlib.h>

/**
 * new -> delete
 * malloc -> free
 */
void good() {
    int *p = new int{};

    int *q = (int *)malloc(sizeof(int));

    delete p;
    free(q);
}

/**
 * forget free or delete the heap space
 */
void bad() {
    int *p = new int{};

    int *q = (int *)malloc(sizeof(int));
}

int main() {
    good();
}