#include <bitset>
#include <cstdint>
#include <iostream>

#define USE_DEFAULT 0

struct Node {
    uint8_t  x = 0;
    uint32_t y = 0;

#if !USE_DEFAULT
    /**
     * Really a fun
     */
    Node& operator=(Node& rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        return *this;
    }
#endif
};
constexpr size_t Len = sizeof(Node) * 8;

// Please by ref
void show_bits(Node& node) {
    using T = uint64_t;
    std::cout << std::bitset<Len>(*(T*)&node) << std::endl;
}

int main() {
    Node node1{0x0001, 0x3f3f};
    Node node2;  // memory not all 0

    show_bits(node1);
    show_bits(node2);

    std::cout << ">>> Copy" << std::endl;
    node2 = node1;
    show_bits(node2);
}