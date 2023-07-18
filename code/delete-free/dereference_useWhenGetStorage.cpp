/**
 * when i first saw the code;
 * I could not breath for a long long time;
 */

/**
 * munmap_chunk(): invalid pointer
 * Aborted (core dumped)
 */
void bad() {
    int p = *new int{};
    delete &p;
}

void good() {
    int *p = new int{};
    delete p;
}

int main() {
    good();
}