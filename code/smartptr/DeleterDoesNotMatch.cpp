#include <memory>

int main() {
    // destructor will use delete， UB
    // type mismatch
    // int != int[]
    { std::shared_ptr<int> bad(new int[10]); }

    // type matching
    { std::shared_ptr<int[]> good(new int[10]); }

    // deleter by self
    { std::shared_ptr<int> good(new int[10], std::default_delete<int[]>()); }
}