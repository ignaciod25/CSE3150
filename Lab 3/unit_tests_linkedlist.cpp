#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

#include <iostream>


TEST_CASE("Pointer Jumping Test") {
    const int size = 5; 

    LinkedList linkedList(size);

    SUBCASE("Check Initial State") {
        CHECK(linkedList.getNodeAddresses() == linkedList.getOriginalNodeAddresses());
    }

    SUBCASE("Perform Pointer Jumping") {
        linkedList.performPointerJumping();
        CHECK(linkedList.getNodeAddresses() == std::list<int>(size, linkedList.getOriginalNodeAddresses().back()));
    }
}




