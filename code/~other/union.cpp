#include <iostream>

class Node {
public:
    int x;
    Node() : x(114514) {
        std::cout << __func__ << std::endl;
    }
    ~Node() {
        std::cout << __func__ << std::endl;
    }
};

union U {
    U() {}
    ~U() {}

    Node obj;
};

int main() {
    U u;

    /**
     * Attention Please:
     * `U0::obj` is not completed construction
     * Though it can run through in some compilers
     */
    // std::cout << u0.obj.x << std::endl;

    // call placement new
    new (&u.obj) Node();
    std::cout << u.obj.x << std::endl;
    // call destructor
    u.obj.~Node();
}
