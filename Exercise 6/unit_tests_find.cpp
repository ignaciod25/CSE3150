#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <vector>
#include "int_vector.h"


bool myfind(const std::vector<int>& vec, int value) {
    for (int element : vec) {
        if (element == value) {
            return true;
        }
    }
    return false;
}

TEST_CASE("myfind") {
    SUBCASE("Edge cases") {
        std::vector<int> x_0 = {};
        bool answer = myfind(x_0, 99);
        CHECK(false == answer);

        std::vector<int> x_1 = {-17};
        answer = myfind(x_1, -17);
        CHECK(true == answer);
        answer = myfind(x_1, 555);
        CHECK(false == answer);
    };

    SUBCASE("Small cases") {
        std::vector<int> x = {1, 5, 8, 11, 25, 30, 32, 47, 78, 99, 101};
        bool foundIt_not = myfind(x, 33);
        CHECK(false == foundIt_not);

        bool foundIt_did = myfind(x, x[4]);
        CHECK(true == foundIt_did);
    };

    SUBCASE("Additional cases") {
    std::vector<int> x = {2, 4, 6, 8, 10};
    bool foundIt_even = myfind(x, 6);
    CHECK(true == foundIt_even);

    bool foundIt_odd = myfind(x, 5);
    CHECK(false == foundIt_odd);

    SUBCASE("Struct constructor") {
    int_vector v(42, 10, 20);
    CHECK(v.id == 42);
    CHECK(v.from == 10);
    CHECK(v.to == 20);
}

SUBCASE("Struct copy-constructor") {
    int_vector original(1, 5, 10);
    int_vector copy(original);
    CHECK(copy.id == original.id);
    CHECK(copy.from == original.from);
    CHECK(copy.to == original.to);
}

SUBCASE("Empty file input") {
    std::vector<int_vector> my_int_vector;
    std::ifstream empty_file("empty_file.txt");

    int id = 0;
    int from, to;
    while (empty_file >> from >> to) {
        int_vector one_int_vector = int_vector(id++, from, to);
        my_int_vector.push_back(one_int_vector);
    }

    CHECK(my_int_vector.empty() == true);
    empty_file.close();
}

}

}
