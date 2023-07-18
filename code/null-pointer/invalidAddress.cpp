#include <iostream>

void fun(const int *p) {
    std::printf("p=[%p] val=[%d]\n", p, *p);
}

int main() {
    
    int *p = new int;
    fun(p);

    // access invalid address
    delete p;
    fun(p);
    
    // access zero
    p = nullptr;
    fun(p);
}
