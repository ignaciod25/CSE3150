#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "lambda_functions.h"

TEST_CASE("perfect numbers") {
    CHECK(is_perfect(6) == true);
    CHECK(is_perfect(28) == true);
    CHECK(is_perfect(496) == true);
    CHECK(is_perfect(8128) == true);
}

TEST_CASE("non perfect numbers") {
    CHECK(is_perfect(12) == false);
    CHECK(is_perfect(21) == false);
    CHECK(is_perfect(100) == false);
}

TEST_CASE("edge cases") {
    CHECK(is_perfect(1) == false); 
    CHECK(is_perfect(0) == false); 
    CHECK(is_perfect(2) == false); 
    CHECK(is_perfect(-6) == false); 
}

TEST_CASE("large numbers") {
    CHECK(is_perfect(33550336) == true); 
    CHECK(is_perfect(123456789) == false); 
}

TEST_CASE("prime numbers") {
    CHECK(is_perfect(5) == false);  
    CHECK(is_perfect(17) == false); 
    CHECK(is_perfect(23) == false); 
}

TEST_CASE("negative numbers") {
    CHECK(is_perfect(-28) == false);
    CHECK(is_perfect(-7) == false);
    CHECK(is_perfect(-2) == false);
}

TEST_CASE("mixed cases") {
    CHECK(is_perfect(10) == false);   
    CHECK(is_perfect(13) == false);    
    CHECK(is_perfect(27) == false);    
    CHECK(is_perfect(29) == false);
    CHECK(is_perfect(30) == false);    
    CHECK(is_perfect(31) == false);    
}


// g++ -o unittests lambda_main.cpp lambda_unittests.cpp