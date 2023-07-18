#define ARRAY_LEN 10

/**
 * new -> delete
 * new [] -> delete []
*/
void good() {
    int *p = nullptr;
    p = new int[ARRAY_LEN]{};
    delete[] p;

    p = new int{};
    delete p;
}

/**
 * Mismatched
 */
void bad() {
    int *p = nullptr;
    p = new int[ARRAY_LEN]{};
    delete p;

    p = new int{};
    delete[] p;
}

int main() {
    good();
}