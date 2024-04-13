#include <iostream>
#include <memory>

#include "CircularList.h"

using namespace std;

void LinkedList::build_node_list(int k) {
    root = make_shared<Node>(Node(1, nullptr));
    shared_ptr<Node> current = root;
    for (int i = 2; i <= k; ++i) {
        current->next = make_shared<Node>(Node(i, nullptr));
        current = current->next;
    }
    current->next = root;
    nodeCount = k;
}

LinkedList::CopyNode* LinkedList::build_copyNodes_weak_ptrs() {
    CopyNode* copyNodes = new CopyNode[nodeCount];
    shared_ptr<Node> current = root;
    for (int i = 0; i < nodeCount; ++i) {
        copyNodes[i].weak_node_ptr = current;
        current = current->next;
    }
    return copyNodes;
}

void LinkedList::delete_node_shared_ptr_list() {
    root = nullptr;
    nodeCount = 0;
}

void LinkedList::print_node_list_shared_ptrs() {
    shared_ptr<Node> current = root;
    std::cout << "Shared Pointers: ";
    for (int i = 0; i < nodeCount; ++i) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


void LinkedList::print_node_array_weak_ptrs() {
    CopyNode* copyNodes = build_copyNodes_weak_ptrs();
    for (int i = 0; i < nodeCount; ++i) {
        cout << copyNodes[i].weak_node_ptr.lock() << endl;
    }
    delete[] copyNodes;
}

LinkedList::LinkedList() {
    nodeCount = 0;
    root = nullptr;
}

LinkedList::~LinkedList() {
    delete_node_shared_ptr_list();
}