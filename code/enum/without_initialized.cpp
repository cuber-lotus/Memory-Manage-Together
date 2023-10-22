#include <stdio.h>
#define N 5

enum Rgb { Red, Green, Blue };

int main() {
    // Enums are not initialized automatically
    enum Rgb color[N];
    for (int i = 0; i < N; i += 1) {
        switch (color[i]) {
        case Red: {
            printf("Red\n");
        } break;
        case Green: {
            printf("Green\n");
        } break;
        case Blue: {
            printf("Blue\n");
        } break;
        default: {
            printf("default val = %d\n", color[i]);
        } break;
        }
    }
}

/*
Possible outputs:

default val = 6422376
default val = 4200123
default val = 4200016
Red
default val = 46
*/