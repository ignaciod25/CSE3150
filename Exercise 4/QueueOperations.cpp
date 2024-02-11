#include <string>
#include "QueueOperations.h"
#include <fstream>
#include <stdexcept>


void pushToQueue(std::queue<MyStruct>& myQueue, const std::string& filename) {
    std::ifstream file(filename);

    MyStruct temp;
    while (file >> temp.value) {
        myQueue.push(temp);
    }

    file.close();
}

void popFromQueue(std::queue<MyStruct>& myQueue) {
    if (myQueue.empty()) {
        throw std::runtime_error("queue is empty");
    }

    myQueue.pop();
}
