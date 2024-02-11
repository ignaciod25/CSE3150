#ifndef STACK_OPERATIONS_H
#define STACK_OPERATIONS_H

#include <stack>
#include <string>
#include "StructDefinition.h"

void pushToStack(std::stack<MyStruct>& myStack, const std::string& filename);
void popFromStack(std::stack<MyStruct>& myStack);

#endif