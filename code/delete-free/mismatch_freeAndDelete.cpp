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
 * free or delete match error
 */
void bad() {
    int *p = new int{};
    int *q = (int *)malloc(sizeof(int));

    free(p);
    delete q;
}

int main() {
    bad();
}