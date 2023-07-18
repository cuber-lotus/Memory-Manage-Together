/**
 * https://www.zhihu.com/question/23367698
 */
#include <iostream>
#include <vector>

int main() {
    std::vector<bool> vb(10);
    // auto is a reference
    auto b = vb[0];
    vb.~vector();
    // now `b` will be dangling
}