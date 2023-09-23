#include <iostream>
#include <vector>

void show(std::vector<int> &arr) {
    // endless loop
    // i -> int
    // vector<>::size -> unsigned
    // unsigned & signed -> unsigned
    for (int i = 0; i < arr.size() - 1; i += 1) {
        std::cout << arr[i] << ' ';
    }
}

int main() {
    std::vector<int> arr;
}