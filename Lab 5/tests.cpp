#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <fstream>
#include <vector>
#include "ints_read_matrix.h"

TEST_CASE("Testing ints_read_matrix function") {
    SUBCASE("Reading zero matrix") {
        std::ifstream in_file("graph_0.txt");
        std::vector<std::vector<int>> zero_matrix = ints_read_matrix(in_file);
        CHECK(zero_matrix.size() == 3);
        CHECK(zero_matrix[0].size() == 3);
        CHECK(zero_matrix[1].size() == 3);
        CHECK(zero_matrix[2].size() == 3);
        CHECK(zero_matrix[0][0] == 0);
        CHECK(zero_matrix[0][1] == 0);
        CHECK(zero_matrix[0][2] == 0);
        CHECK(zero_matrix[1][0] == 0);
        CHECK(zero_matrix[1][1] == 0);
        CHECK(zero_matrix[1][2] == 0);
        CHECK(zero_matrix[2][0] == 0);
        CHECK(zero_matrix[2][1] == 0);
        CHECK(zero_matrix[2][2] == 0);
    }

    SUBCASE("Reading plus one matrix") {
        std::ifstream in_file("graph_1.txt");
        std::vector<std::vector<int>> plus_one_matrix = ints_read_matrix(in_file);
        CHECK(plus_one_matrix.size() == 3);
        CHECK(plus_one_matrix[0].size() == 3);
        CHECK(plus_one_matrix[1].size() == 3);
        CHECK(plus_one_matrix[2].size() == 3);
        // Add more checks as needed for the specific content of the plus one matrix
    }

    SUBCASE("Reading minus one matrix") {
        std::ifstream in_file("graph_m1.txt");
        std::vector<std::vector<int>> minus_one_matrix = ints_read_matrix(in_file);
        CHECK(minus_one_matrix.size() == 3);
        CHECK(minus_one_matrix[0].size() == 3);
        CHECK(minus_one_matrix[1].size() == 3);
        CHECK(minus_one_matrix[2].size() == 3);
        // Add more checks as needed for the specific content of the minus one matrix
    }
}
