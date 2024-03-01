#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class MatrixOperations {
public:
    void InitAdjacencyMatrices(const char* fileD1, const char* fileD0, const char* fileDMinus1);
    void ExpensiveDigraphExactPaths();

    bool IsPathExists(int startNode, int endNode) const;
    int GetShortestPathLength(int startNode, int endNode) const;
    
    const std::vector<std::vector<int>>& GetD1() const {
            return D1;
        }

        const std::vector<std::vector<int>>& GetD0() const {
            return D0;
        }

        const std::vector<std::vector<int>>& GetDMinus1() const {
            return DMinus1;
        }
private:
    std::vector<std::vector<int>> D1, D0, DMinus1;

    void ReadMatrixFromStream(std::ifstream& inStream, std::vector<std::vector<int>>& matrix);
    void PrintMatrix(const std::vector<std::vector<int>>& matrix);

    

};

#endif