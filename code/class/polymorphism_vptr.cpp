#include <cstring>
#include <iostream>

class Base {
public:
    Base() {
        // change the vptr
        memset(this, 0, sizeof(*this));
    }

    virtual void fun() {
        ::std::cout << __func__ << __LINE__ << ::std::endl;
    }
};

int main() {
    // not a polymorphism call
    Base obj;
    obj.fun();

    // a polymorphism call
    // Segmentation fault (core dumped)
    Base* p = new Base{};
    p->fun();
    delete p;
}