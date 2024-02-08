#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fisher_yates.h"


TEST_CASE("Fisher-Yates Shuffle Test") {
    const int size = 10;
    int originalArray[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int shuffledArray[size];


    std::copy(std::begin(originalArray), std::end(originalArray), std::begin(shuffledArray));


    fisherYatesShuffle(shuffledArray, size);


    CHECK(std::distance(std::begin(originalArray), std::end(originalArray)) == size);


    for (int i = 0; i < size; ++i) {
        CHECK(std::find(std::begin(shuffledArray), std::end(shuffledArray), originalArray[i]) !=
              std::end(shuffledArray));
    }

    CHECK(std::memcmp(originalArray, shuffledArray, size * sizeof(int)) != 0);

 
}
