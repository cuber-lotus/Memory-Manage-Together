#include <stdio.h>
#include <string.h>

int main() {
    char src[]   = "Hello World!";
    char dest[5] = "";

    // copy src -> dest
    // sizeof(src) > sizeof(dest)
    memcpy(dest, src, sizeof(src));

    printf("src len=[%u] =[%s]\n", (unsigned)sizeof(src), src);
    printf("dest len=[%u] =[%s]\n", (unsigned)sizeof(dest), dest);
}