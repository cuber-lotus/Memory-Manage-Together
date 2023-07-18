/**
 * @file circular-reference_01.cpp
 * @brief cross circular reference
 */
#include <iostream>
#include <memory>

struct A;
struct B;

struct A {
    std::shared_ptr<B> ptr;
    A() {
        std::cout << __func__ << std::endl;
    }
    ~A() {
        std::cout << __func__ << std::endl;
    }
};

struct B {
    std::shared_ptr<A> ptr;
    B() {
        std::cout << __func__ << std::endl;
    }
    ~B() {
        std::cout << __func__ << std::endl;
    }
};

int main() {
    auto pa = std::make_shared<A>();
    auto pb = std::make_shared<B>();

    pa->ptr = pb;
    pb->ptr = pa;
}