#include <iostream>
#include <memory>

#include "CircularList.h"

using namespace std;

int main() {
    LinkedList cll;
    cll.build_node_list(5);
    cout << "Shared Pointers: ";
    cll.print_node_list_shared_ptrs();
    cout << "Weak Pointers: " << endl;
    cll.print_node_array_weak_ptrs();
    cll.delete_node_shared_ptr_list();
    cout << "After deletion of shared pointers: ";
    cll.print_node_list_shared_ptrs();
    cout << "Weak Pointers after deletion of shared pointers: " << endl;
    cll.print_node_array_weak_ptrs();
    return 0;
}