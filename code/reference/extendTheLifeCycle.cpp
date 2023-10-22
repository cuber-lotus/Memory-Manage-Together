/**
 * The code can't extend the life cycle of the char[]{"Hello World!"}.
 * Though it can run through in some compilers.
*/
#include <iostream>
#include <string>

const std::string& fun(const std::string& s) {
    std::cout << s << std::endl;
    return s;
}

int main() {
    const std::string& s = fun("Hello World!");
    std::cout << s << std::endl;
}
