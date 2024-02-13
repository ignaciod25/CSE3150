#include "linked_list.h"
#include <iostream>

int main() {
    const int size = 5; 

    LinkedList linkedList(size);


    std::cout << "original list ";
    for (int value : linkedList.getOriginalNodeAddresses()) {
        std::cout << value << " ";
    }
    std::cout << std::endl;


    linkedList.performPointerJumping();


    std::cout << "modified list: ";
    for (int value : linkedList.getNodeAddresses()) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
