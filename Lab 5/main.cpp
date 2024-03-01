#include "matrix_operations.h"

int main() {
    MatrixOperations matrixOps;
    matrixOps.InitAdjacencyMatrices("D1.txt", "D0.txt", "D-1.txt");
    matrixOps.ExpensiveDigraphExactPaths();

    return 0;
}
