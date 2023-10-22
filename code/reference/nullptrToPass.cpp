#include <string>

/**
 * @brief
 * Even if it's passing by value by reference.
 * There is no guarantee that this is a legitimate pass.
 * @param s
 */
void fun(const std::string& s) {
    // fun
}

int main() {
    std::string* p_str = nullptr;
    // The syntax is correct.
    fun(*p_str);
}
