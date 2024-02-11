#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "StackOperations.h"
#include "QueueOperations.h"

TEST_CASE("Stack Operations") {
    std::stack<MyStruct> myStack;
    CHECK_NOTHROW(pushToStack(myStack, "test_input.txt"));
    CHECK_NOTHROW(popFromStack(myStack));
}

TEST_CASE("Queue Operations") {
    std::queue<MyStruct> myQueue;
    CHECK_NOTHROW(pushToQueue(myQueue, "test_input.txt"));
    CHECK_NOTHROW(popFromQueue(myQueue));
}

TEST_CASE("Negative Sum Exception - Stack") {
    std::stack<MyStruct> myStack;
    CHECK_NOTHROW(pushToStack(myStack, "test_input_negative_sum.txt"));
    CHECK_THROWS_AS(popFromStack(myStack), std::runtime_error);
}

TEST_CASE("Negative Sum Exception - Queue") {
    std::queue<MyStruct> myQueue;
    CHECK_NOTHROW(pushToQueue(myQueue, "test_input_negative_sum.txt"));
    CHECK_THROWS_AS(popFromQueue(myQueue), std::runtime_error);
}
