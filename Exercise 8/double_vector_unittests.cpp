#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "double_vector.h"

TEST_CASE("dot_product function") {
    SUBCASE("Dot product of two vectors") {
        double_vector a(1.0, 2.0);
        double_vector b(3.0, 4.0);
        double result = dot_product(a, b);
        CHECK(result == 11.0);
    }

    SUBCASE("Dot product with zero vector") {
        double_vector a(0.0, 0.0);
        double_vector b(1.0, 2.0);
        double result = dot_product(a, b);
        CHECK(result == 0.0);
    }
}

TEST_CASE("magnitude function") {
    SUBCASE("Magnitude of a vector") {
        double_vector v(3.0, 4.0);
        double result = magnitude(v);
        CHECK(result == doctest::Approx(5.0));
    }

    SUBCASE("Magnitude of zero vector") {
        double_vector v(0.0, 0.0);
        double result = magnitude(v);
        CHECK(result == 0.0);
    }
}

TEST_CASE("cosine_distance function") {
    SUBCASE("Cosine distance of identical vectors") {
        double_vector a(1.0, 0.0);
        double_vector b(1.0, 0.0);
        double result = cosine_distance(a, b);
        CHECK(result == doctest::Approx(0.0)); 
    }

    SUBCASE("Cosine distance of orthogonal vectors") {
        double_vector a(1.0, 0.0);
        double_vector b(0.0, 1.0);
        double result = cosine_distance(a, b);
        CHECK(result == doctest::Approx(1.5708)); 
    }
}

TEST_CASE("double_vector constructor") {
    SUBCASE("Constructor with x and y coordinates") {
        double x = 3.0;
        double y = 4.0;
        double_vector v(x, y);
        CHECK(v.x == x);
        CHECK(v.y == y);
    }
}

TEST_CASE("dot_product function") {
    SUBCASE("Dot product of two vectors") {
        double_vector a(2.0, 3.0);
        double_vector b(4.0, 5.0);
        double result = dot_product(a, b);
        CHECK(result == 23.0);
    }

    SUBCASE("Dot product with zero vector") {
        double_vector a(0.0, 0.0);
        double_vector b(1.0, 2.0);
        double result = dot_product(a, b);
        CHECK(result == 0.0);
    }
}

TEST_CASE("magnitude function") {
    SUBCASE("Magnitude of a vector") {
        double_vector v(3.0, 4.0);
        double result = magnitude(v);
        CHECK(result == doctest::Approx(5.0));
    }

    SUBCASE("Magnitude of zero vector") {
        double_vector v(0.0, 0.0);
        double result = magnitude(v);
        CHECK(result == 0.0);
    }
}


