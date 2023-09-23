#include <iostream>
#include <memory>

struct Node {
    Node() {
        std::cout << this << __func__ << std::endl;
    }
    
    ~Node() {
        std::cout << this << __func__ << std::endl;
    }
};

template <typename T>
using smart_ptr = std::shared_ptr<T>;

int main() {
    auto *p = new Node{};

    smart_ptr<Node> sp0(p);
    // free(): double free detected in tcache 2
    smart_ptr<Node> sp1(p);
}