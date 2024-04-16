#include <iostream>
#include <memory>

struct A {
    std::unique_ptr<A> ptr;

    A() {
        std::printf("[%p] %s\n", this, __func__);
    }

    /**
     * Run recursively through '`std::unique_ptr'
     */
    ~A() {
        std::printf("[%p] %s\n", this, __func__);
    }
};

int main() {
    auto pa = std::make_shared<A>();
    auto pb = std::make_shared<A>();

    // cross circular reference
    pa->ptr.reset(pb.get());
    pb->ptr.reset(pa.get());

    std::cout << ">>> main end" << std::endl;
}