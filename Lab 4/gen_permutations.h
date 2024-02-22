#ifndef GEN_PERMUTATIONS_H
#define GEN_PERMUTATIONS_H

#include <vector>

std::vector<int> generateWellBalancedList(int n);
int findLowestValleyDepth(const std::vector<int>& symbols);
std::vector<int> getPathToLowestValley(const std::vector<int>& symbols, int depth);
std::vector<int> getLowestValleyToEndPath(const std::vector<int>& symbols, int depth);
void dropLastNegativeEdge(std::vector<int>& path);

#endif 
