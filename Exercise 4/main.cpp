#include "StackOperations.h"
#include "QueueOperations.h"
#include <stack>
#include <queue>
#include <iostream>

int main() {
    std::stack<MyStruct> myStack;
    std::queue<MyStruct> myQueue;

    try {

        pushToStack(myStack, std::string("test_input.txt"));


        popFromStack(myStack);


        pushToQueue(myQueue, std::string("test_input.txt"));


        popFromQueue(myQueue);

    } catch (const std::exception& e) {

        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "program executed" << std::endl;

    return 0;
}
