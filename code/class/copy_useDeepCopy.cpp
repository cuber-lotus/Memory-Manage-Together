/**
 * deep copy operator
 */
void good() {
    class Node {
    private:
        int* p;

    public:
        Node() : p(new int{}) {
        }

        ~Node() {
            if (p != nullptr) {
                delete p;
                p = nullptr;
            }
        }

        // copy operator=
        // deep copy
        Node& operator=(const Node& rhs) {
            this->~Node();
            p = new int{*rhs.p};
        }
    };

    Node node;
    // deep copy
    node = Node();
}

/**
 * free(): double free detected in tcache 2
 * Aborted (core dumped)
 */
void bad() {
    class Node {
    private:
        int* p;

    public:
        Node() : p(new int{}) {
        }

        ~Node() {
            if (p != nullptr) {
                delete p;
                p = nullptr;
            }
        }
    };

    Node node;
    // shallow copy
    node = Node();
}

int main() {
    good();
}