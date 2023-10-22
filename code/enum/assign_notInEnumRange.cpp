enum class Rgb { Red, Green, Blue };

/**
 * @brief 
 * Please check the value before use it.
 * @param rgb 
 */
void fun(Rgb rgb) {
    // pass
}

int main() {
    // enumerate can assign the value which is not in the enum range.
    Rgb x = static_cast<Rgb>(114514);
    fun(x);
}
