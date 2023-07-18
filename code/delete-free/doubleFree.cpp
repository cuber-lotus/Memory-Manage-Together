#include <iostream>

class Node {
public:
    int *p;
    Node() : p(new int{114514}) {
        std::cout << __func__ << std::endl;
    }
    ~Node() {
        std::cout << __func__ << std::endl;
        delete p;
    }
};

void bad_00() {
    Node p;
    // the first time
    p.~Node();
}  // the second time

void bad_01() {
    int *p = new int;
    delete p;
    delete p;
}

int main() {
    bad_01();
}
