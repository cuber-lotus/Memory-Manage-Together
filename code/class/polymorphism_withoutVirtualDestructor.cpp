#include <iostream>

class Base {
private:
    int* p;

public:
    Base() : p(new int{}) {}

    // //  bad
    // ~Base() {
    //     delete p;
    //     ::std::cout << __func__ << ::std::endl;
    // }

    //  good
    virtual ~Base() {
        delete p;
        ::std::cout << __func__ << ::std::endl;
    }
};

class Derive final : public Base {
public:
    Derive() {}

    ~Derive() {
        ::std::cout << __func__ << ::std::endl;
    }
};

int main() {
    Base* p = new Derive{};

    delete p;
}