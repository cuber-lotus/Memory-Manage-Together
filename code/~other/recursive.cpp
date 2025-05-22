/**
 * recursive function
 * stack bomb
 */
int fun(int x) {
    return x + fun(x - 1);
}

int main() {
    fun(10);
}