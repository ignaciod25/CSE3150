#include "matrix_operations.h"
#include <iostream>

void MatrixOperations::InitAdjacencyMatrices(const char* fileD1, const char* fileD0, const char* fileDMinus1) {

    std::ifstream inD1(fileD1);
    std::ifstream inD0(fileD0);
    std::ifstream inDMinus1(fileDMinus1);

    


    ReadMatrixFromStream(inD1, D1);
    ReadMatrixFromStream(inD0, D0);
    ReadMatrixFromStream(inDMinus1, DMinus1);
}

void MatrixOperations::ReadMatrixFromStream(std::ifstream& inStream, std::vector<std::vector<int>>& matrix) {

    std::string line;
    while (std::getline(inStream, line)) {
        std::istringstream iss(line);
        std::vector<int> row;

        int value;
        while (iss >> value) {
            row.push_back(value);
        }

        matrix.push_back(row);
    }
}


    void MatrixOperations::ExpensiveDigraphExactPaths() {

    int n = D1.size(); 


    std::vector<std::vector<int>> R1(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> R0(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> RMinus1(n, std::vector<int>(n, 0));


    std::vector<std::vector<int>> temp1(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> temp2(n, std::vector<int>(n, 0));


    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            R0[i][j] = (D0[i][j] == 0) ? 1 : 0;


    for (int k = -1; k <= 1; ++k) {

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                temp1[i][j] = DMinus1[i][j] * R0[i][j];


        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                RMinus1[i][j] = std::max(DMinus1[i][j], temp1[i][j]);


        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                temp2[i][j] = RMinus1[i][j] * D1[i][j];


        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                R1[i][j] = std::max(D1[i][j], temp2[i][j]);
    }


    D1 = R1;
    D0 = R0;
    DMinus1 = RMinus1;


    std::cout << "D1 Matrix:\n";
    PrintMatrix(D1);
    std::cout << "\nD0 Matrix:\n";
    PrintMatrix(D0);
    std::cout << "\nD-1 Matrix:\n";
    PrintMatrix(DMinus1);
}


void MatrixOperations::PrintMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}
