#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <sstream>
#include <string>
#include <vector>

#include "ints_read_matrix.h"

TEST_CASE("Read matrix from stream") {
    std::istringstream input("1 2 3\n4 5 6\n7 8 9");
    std::vector<std::vector<int>> result = ints_read_matrix(input);

    CHECK(result.size() == 3);

    CHECK(result[0] == std::vector<int>{1, 2, 3});
    CHECK(result[1] == std::vector<int>{4, 5, 6});
    CHECK(result[2] == std::vector<int>{7, 8, 9});
}

TEST_CASE("Read vector from stream") {
    std::istringstream input("1 2 3 4 5");
    std::vector<int> result = ints_read(input);

    CHECK(result.size() == 5);
    CHECK(result == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Read one line of ints from stream") {
    std::istringstream input("1 2 3 4 5");
    std::vector<int> result = ints_read_one_line(input);

    CHECK(result.size() == 5);
    CHECK(result == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Read ints until a terminal value from stream") {
    std::istringstream input("1 2 3 4 5 terminal");
    std::vector<int> result = ints_read(input, "terminal");

    CHECK(result.size() == 5);
    CHECK(result == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Output vector to stream") {
    std::ostringstream output;
    std::vector<int> vec{1, 2, 3, 4, 5};
    output << vec;

    CHECK(output.str() == "1 2 3 4 5 ");
}

TEST_CASE("Output matrix to stream") {
    std::ostringstream output;
    std::vector<std::vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    output << matrix;

    CHECK(output.str() == "1 2 3 4 5 6 7 8 9 \n");
}
