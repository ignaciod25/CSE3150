#ifndef QUEUE_OPERATIONS_H
#define QUEUE_OPERATIONS_H

#include <queue>
#include <string>
#include "StructDefinition.h"

void pushToQueue(std::queue<MyStruct>& myQueue, const std::string& filename);
void popFromQueue(std::queue<MyStruct>& myQueue);

#endif
