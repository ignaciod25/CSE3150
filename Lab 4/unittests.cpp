#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "gen_permutations.h"

TEST_CASE("Test generateWellBalancedList") {

    auto result1 = generateWellBalancedList(2);
    CHECK(result1.size() == 4);

    auto result2 = generateWellBalancedList(3);
    CHECK(result2.size() == 6);


    CHECK(std::count(result1.begin(), result1.end(), 1) >= 1);
    CHECK(std::count(result1.begin(), result1.end(), -1) >= 1);

    CHECK(std::count(result2.begin(), result2.end(), 1) >= 2);
    CHECK(std::count(result2.begin(), result2.end(), -1) >= 2);

}

