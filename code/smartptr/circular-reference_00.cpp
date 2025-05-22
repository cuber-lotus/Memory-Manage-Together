/**
 * @file circular-reference_00.cpp
 * @brief
 * circular reference by self
 */
#include <iostream>
#include <memory>

struct Node {
    std::shared_ptr<Node> ptr;
    Node() {
        std::cout << __func__ << std::endl;
    }
    ~Node() {
        std::cout << __func__ << std::endl;
    }
};

int main() {
    auto ptr = std::make_shared<Node>();
    ptr->ptr = ptr;
}