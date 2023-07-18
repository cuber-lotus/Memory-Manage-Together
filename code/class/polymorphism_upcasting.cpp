#include <iostream>

class Base {
public:
    Base() {
        std::cout << __func__ << __LINE__ << std::endl;
    }

    virtual ~Base() {
        std::cout << __func__ << __LINE__ << std::endl;
    }

    virtual void fun() {
        std::cout << __func__ << __LINE__ << std::endl;
    }
};

class Derive final : public Base {
public:
    Derive() {
        std::cout << __func__ << __LINE__ << std::endl;
    }

    ~Derive() {
        std::cout << __func__ << __LINE__ << std::endl;
    }
    
    virtual void fun() {
        std::cout << __func__ << __LINE__ << std::endl;
    }
};

int main() {
    // In most cases there are problems
    Base b;
    Derive* p = dynamic_cast<Derive*>(&b);
    p->fun();
}