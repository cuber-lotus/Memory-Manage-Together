/**
 * @file pointer-element.cpp
 * @brief
 * Attention please
 *  Notice the life cycle of elements inside the container
 *  Especially when the elements are Pointers
 */
#include <memory>
#include <vector>
#define CON_SIZE 5

void bad() {
    std::vector<int*> vp;
    for (int i = 0; i < CON_SIZE; i += 1) {
        vp.push_back(new int{i});
    }
}

// free by user
void good_00() {
    std::vector<int*> vp;
    for (int i = 0; i < CON_SIZE; i += 1) {
        vp.push_back(new int{i});
    }

    for (size_t i = 0; i < vp.size(); i += 1) {
        delete vp[i];
    }
}

// free by smartptr
void good_01() {
    using T = int;

    std::vector<std::unique_ptr<int>> vp;
    for (int i = 0; i < CON_SIZE; i += 1) {
        vp.push_back(std::make_unique<int>(i));
    }
}

int main() {
    good_01();
}