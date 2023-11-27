#include <iostream>
#include <vector>

void fun(int n) {
    std::vector<int>  arr;
    std::vector<int*> arrPtr;

    for (int i = 0; i < n; i += 1) {
        // std::vector<> will dilatation
        arr.push_back(i);
        arrPtr.push_back(&arr[i]);
    }

    for (int i = 0; i < n; i += 1) {
        std::cout << "val=" << arr[i] << " ptr=" << *arrPtr[i] << std::endl;
    }
}

int main() {
    fun(10);
}
