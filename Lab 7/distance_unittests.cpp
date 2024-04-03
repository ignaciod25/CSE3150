#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "double_vector.h"
#include "distance.h"

TEST_CASE("Test square function") {
    SUBCASE("Positive number") {
        CHECK_EQ(square(4.0), 16.0);
    }

    SUBCASE("Negative number") {
        CHECK_EQ(square(-3.0), 9.0);
    }

    SUBCASE("Zero") {
        CHECK_EQ(square(0.0), 0.0);
    }

     SUBCASE("Large number") {
        CHECK_EQ(square(100.0), 10000.0);
    }

    SUBCASE("Fractional number") {
        CHECK_EQ(square(0.5), 0.25);
    }
}

TEST_CASE("Test dot_product function") {
    SUBCASE("Positive numbers") {
        double_vector vec1 = {1.0, 2.0, 0};
        double_vector vec2 = {3.0, 4.0, 0};
        CHECK_EQ(dot_product(vec1, vec2), 11.0);
    }

    SUBCASE("Negative numbers") {
        double_vector vec1 = {-1.0, -2.0, 0};
        double_vector vec2 = {3.0, 4.0, 0};
        CHECK_EQ(dot_product(vec1, vec2), -11.0);
    }

    SUBCASE("One vector is zero") {
        double_vector vec1 = {0.0, 0.0, 0};
        double_vector vec2 = {3.0, 4.0, 0};
        CHECK_EQ(dot_product(vec1, vec2), 0.0);
    }

    SUBCASE("Orthogonal vectors") {
        double_vector vec1 = {1.0, 0.0, 0};
        double_vector vec2 = {0.0, 1.0, 0};
        CHECK_EQ(dot_product(vec1, vec2), 0.0);
    }
}

TEST_CASE("Test magnitude function") {
    SUBCASE("Positive numbers") {
        double_vector vec = {3.0, 4.0, 0};
        CHECK_EQ(magnitude(vec), 5.0);
    }

    SUBCASE("Negative numbers") {
        double_vector vec = {-3.0, -4.0, 0};
        CHECK_EQ(magnitude(vec), 5.0);
    }

    SUBCASE("Zero vector") {
        double_vector vec = {0.0, 0.0, 0};
        CHECK_EQ(magnitude(vec), 0.0);
    }

    SUBCASE("Negative fractional numbers") {
        double_vector vec = {-0.5, -0.5, 0};
        CHECK_EQ(magnitude(vec), doctest::Approx(0.70710678118).epsilon(0.0001));
    }

    SUBCASE("Large numbers") {
        double_vector vec = {1000.0, 1000.0, 0};
        CHECK_EQ(magnitude(vec), doctest::Approx(1414.21356237).epsilon(0.0001));
    }
}

TEST_CASE("Test my_distance struct") {
    my_distance dist = {1, 2, 0.5};
    CHECK_EQ(dist.id_1, 1);
    CHECK_EQ(dist.id_2, 2);
    CHECK_EQ(dist.cos_distance, 0.5);
}

TEST_CASE("Test cosine_distance function") {
    SUBCASE("Perpendicular vectors") {
        double_vector vec1 = {1.0, 0.0, 0};
        double_vector vec2 = {0.0, 1.0, 0};
        CHECK_EQ(cosine_distance(vec1, vec2), doctest::Approx(1.57079632679).epsilon(0.0001));
    }

    SUBCASE("Parallel vectors") {
        double_vector vec1 = {3.0, 4.0, 0};
        double_vector vec2 = {6.0, 8.0, 0};
        CHECK_EQ(cosine_distance(vec1, vec2), doctest::Approx(0.0).epsilon(0.0001));
    }

    SUBCASE("Opposite direction vectors") {
        double_vector vec1 = {1.0, 0.0, 0};
        double_vector vec2 = {-1.0, 0.0, 0};
        CHECK_EQ(cosine_distance(vec1, vec2), doctest::Approx(3.14159265359).epsilon(0.0001));
    }
}

TEST_CASE("Test my_distance struct") {
    SUBCASE("Check id and cos_distance") {
        my_distance dist = {1, 2, 0.5};
        CHECK_EQ(dist.id_1, 1);
        CHECK_EQ(dist.id_2, 2);
        CHECK_EQ(dist.cos_distance, 0.5);
    }
}




//g++ distance_unittests.cpp double_vector.cpp -o my_tests
