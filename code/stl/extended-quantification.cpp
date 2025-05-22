#include <vector>

int main() {
    std::vector<int*> p;
    std::vector<int>  arr;
    for (int i = 0; i < 10; ++i) {
        arr.push_back(i);
        p.push_back(&arr[i]);
    }

    // due extended quantification the pionters are wild.
    // use 'p'
}