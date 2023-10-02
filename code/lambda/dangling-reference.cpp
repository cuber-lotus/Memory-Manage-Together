auto fun() {
    int x = 10;

    // Dangling reference the 'x'
    return [&] {};
}

int main() {
    auto funObj = fun();

    // use funObj
    // pass
}