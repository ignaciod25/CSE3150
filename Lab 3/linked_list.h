#pragma once

#include <list>

class LinkedList {
public:
    LinkedList(int size);
    ~LinkedList();

    void performPointerJumping();

    const std::list<int>& getNodeAddresses() const;
    const std::list<int>& getOriginalNodeAddresses() const;

private:
    std::list<int> nodeAddresses;
    std::list<int> originalNodeAddresses;
};
