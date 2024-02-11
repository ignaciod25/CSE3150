#include <string>
#include "StackOperations.h"
#include <fstream>
#include <stdexcept>


void pushToStack(std::stack<MyStruct>& myStack, const std::string& filename) {
    std::ifstream file(filename);

    MyStruct temp;
    while (file >> temp.value) {
        myStack.push(temp);
    }

    file.close();
}

void popFromStack(std::stack<MyStruct>& myStack) {
    if (myStack.empty()) {
        throw std::runtime_error("stack is empty");
    }

    myStack.pop();
}
