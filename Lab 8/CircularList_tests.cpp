#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "CircularList.h"
#include <sstream>

TEST_CASE("Building and printing weak pointers array") {
    LinkedList cll;
    cll.build_node_list(3);
    std::stringstream ss;
    cll.print_node_array_weak_ptrs();
    CHECK(ss.str() == "");
}

TEST_CASE("Deleting node shared pointer list") {
    LinkedList cll;
    cll.build_node_list(3);
    cll.delete_node_shared_ptr_list();
    std::stringstream ss;
    cll.print_node_list_shared_ptrs();
    CHECK(ss.str() == "");
}

TEST_CASE("Deleting node shared pointer list doesn't affect weak pointers array") {
    LinkedList cll;
    cll.build_node_list(3);
    LinkedList::CopyNode* copyNodes = cll.build_copyNodes_weak_ptrs();
    cll.delete_node_shared_ptr_list();
    std::stringstream ss;
    for (int i = 0; i < 3; ++i) {
        ss << copyNodes[i].weak_node_ptr.lock() << "\n";
    }
    delete[] copyNodes;
    CHECK(ss.str() != "");
}

TEST_CASE("Building node list with zero elements") {
    LinkedList cll;
    cll.build_node_list(0);
    std::stringstream ss;
    cll.print_node_list_shared_ptrs();
    CHECK(ss.str() == "");
}





