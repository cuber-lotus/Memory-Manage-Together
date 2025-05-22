/**
 * Order of evaluation of any part of any expression,
 * including order of evaluation of function arguments is unspecified
 * 求值任何表达式的任何部分，
 * 包括求值函数参数的顺序都未指明
 *
 * =====================================================
 * https://en.cppreference.com/w/cpp/language/eval_order
 * https://zh.cppreference.com/w/cpp/language/eval_order
 */
#include <iostream>
#include <memory>

int getNum() {
    std::cout << __func__ << std::endl;
    throw 114514;
    return 114514;
}

int* getPointer() {
    std::cout << __func__ << std::endl;
    return new int{};
}

std::shared_ptr<int> getSharePointer() {
    std::cout << __func__ << std::endl;
    return std::make_shared<int>(0);
}

void good() {
    auto fun = [](int x, std::shared_ptr<int> p) {};

    // std::shared_ptr<int> has destructor
    // it is safe
    try {
        fun(getNum(), getSharePointer());
    } catch (...) {
        std::cout << "in catch" << std::endl;
    }
}

void bad() {
    auto fun = [](int x, int* p) {};

    // while getPointer() runs before getNum(){exception},
    // the program will miss the pointer
    try {
        fun(getNum(), getPointer());
    } catch (...) {
        std::cout << "in catch" << std::endl;
    }
}

int main() {
    good();
}