/**
 * C code
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * parameter list is empty
*/
void fun() {
    printf("%s\n", __func__);
}

/**
 * parameter list is void
*/
void foo(void) {
    printf("%s\n", __func__);
}

int main(void) {
    // lose pointer
    fun(malloc(sizeof(char)));

    // compilation failure
    // foo(malloc(sizeof(char)));
}
