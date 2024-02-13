#include "linked_list.h"


LinkedList::LinkedList(int size) {
    for (int i = 0; i < size; ++i) {
        nodeAddresses.push_back(i);
        originalNodeAddresses.push_back(i);
    }
}

LinkedList::~LinkedList() {
}

void LinkedList::performPointerJumping() {
    if (!nodeAddresses.empty()) {
        int lastNode = originalNodeAddresses.back();
        for (int& node : nodeAddresses) {
            node = lastNode;
        }
    }
}

const std::list<int>& LinkedList::getNodeAddresses() const {
    return nodeAddresses;
}

const std::list<int>& LinkedList::getOriginalNodeAddresses() const {
    return originalNodeAddresses;
}
