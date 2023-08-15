#include <memory>

int main() {
    // destructor will use delete， UB
    {
        std::shared_ptr<int> shared_bad(new int[10]);
    }

    // diy delete safe
    {
        std::shared_ptr<int> shared_good(new int[10],
                                         std::default_delete<int[]>());
    }
}