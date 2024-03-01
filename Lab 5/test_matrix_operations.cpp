#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "matrix_operations.h"

TEST_CASE("Matrix Operations Tests") {
    SUBCASE("Initialization and Matrix Reading") {
        MatrixOperations matrixOps;
        CHECK_NOTHROW(matrixOps.InitAdjacencyMatrices("D1.txt", "D0.txt", "D-1.txt"));
        CHECK_FALSE(matrixOps.GetD1().empty());
        CHECK_FALSE(matrixOps.GetD0().empty());

    }

    SUBCASE("Check Matrix Sizes") {
        MatrixOperations matrixOps;
        matrixOps.InitAdjacencyMatrices("D1.txt", "D0.txt", "D-1.txt");

        const auto& D1 = matrixOps.GetD1();
        const auto& D0 = matrixOps.GetD0();
        const auto& DMinus1 = matrixOps.GetDMinus1();

        CHECK_EQ(D1.size(), D0.size());

        
    }

}
