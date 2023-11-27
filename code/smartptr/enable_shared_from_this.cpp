#include <iostream>
#include <memory>

#define ALLOW_SHARE_FROM_THIS (1)

class Node
#if ALLOW_SHARE_FROM_THIS
    : public std::enable_shared_from_this<Node>
#endif
{
public:
    std::shared_ptr<Node> getSelfSharePtr() {
#if ALLOW_SHARE_FROM_THIS
        /**
         * When we use `shared_from_this`
         * Please Make sure a share_ptr<> has been generated from `this`
         */
        return shared_from_this();
#else
        return std::shared_ptr<Node>(this);
#endif
    }
};

void good(Node* p) {
    // The first time to create a std::shared_ptr<>
    std::shared_ptr<Node> sp1 = std::shared_ptr<Node>(p);

    std::shared_ptr<Node> sp2 = p->getSelfSharePtr();
}

void bad(Node* p) {
    // The first time to create a std::shared_ptr<>
    std::shared_ptr<Node> sp1 = std::shared_ptr<Node>(p);

    /**
     * without inherit
     * The same object is controlled (not share) by two std::shared_ptr
     *
     * free(): double free detected in tcache 2
     * Aborted
     */
    std::shared_ptr<Node> sp2 = p->getSelfSharePtr();
}

int main() {
    Node* p = nullptr;
    
#if ALLOW_SHARE_FROM_THIS
    p = new Node();
    good(p);
#else
    p = new Node{};
    bad(p);
#endif

    std::cout << __func__ << __LINE__ << std::endl;
}
