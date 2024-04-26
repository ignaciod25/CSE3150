#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


#include "doctest.h"
#include "Vehicle.h"

TEST_CASE("Gasoline vehicle cost calculation with positive mpg and cost per gallon") {
    Gasoline gasoline;
    gasoline.setMpg(25);
    gasoline.setCostPerGallon(3.4);
    CHECK(gasoline.calculateCostOfTrip(100) == doctest::Approx(13.6));
}

TEST_CASE("Electric vehicle cost calculation with positive mpge and cost per kWh") {
    Electric electric;
    electric.setMpge(120);
    electric.setCostPerkWh(0.18);
    CHECK(electric.calculateCostOfTrip(100) == doctest::Approx(0.15));
}

TEST_CASE("Hybrid vehicle cost calculation with positive mpg, mpge, cost per gallon, and cost per kWh") {
    Hybrid hybrid;
    hybrid.setMpg(25);
    hybrid.setCostPerGallon(3.4);
    hybrid.setMpge(120);
    hybrid.setCostPerkWh(0.18);
    CHECK(hybrid.calculateCostOfTrip(100) == doctest::Approx(6.875));
}

TEST_CASE("Gasoline vehicle cost calculation with zero mpg") {
    Gasoline gasoline;
    gasoline.setMpg(0);
    gasoline.setCostPerGallon(3.4);
    CHECK(gasoline.calculateCostOfTrip(100) == doctest::Approx(0.0));
}

TEST_CASE("Electric vehicle cost calculation with zero mpge") {
    Electric electric;
    electric.setMpge(0);
    electric.setCostPerkWh(0.18);
    CHECK(electric.calculateCostOfTrip(100) == doctest::Approx(0.0));
}

TEST_CASE("Hybrid vehicle cost calculation with zero mpg and mpge") {
    Hybrid hybrid;
    hybrid.setMpg(0);
    hybrid.setCostPerGallon(3.4);
    hybrid.setMpge(0);
    hybrid.setCostPerkWh(0.18);
    CHECK(hybrid.calculateCostOfTrip(100) == doctest::Approx(0.0));
}

TEST_CASE("Hybrid vehicle cost calculation with zero cost per gallon and cost per kWh") {
    Hybrid hybrid;
    hybrid.setMpg(25);
    hybrid.setCostPerGallon(0);
    hybrid.setMpge(120);
    hybrid.setCostPerkWh(0);
    CHECK(hybrid.calculateCostOfTrip(100) == doctest::Approx(0.0));
}


TEST_CASE("Gasoline vehicle cost calculation with small trip distance") {
    Gasoline gasoline;
    gasoline.setMpg(30);
    gasoline.setCostPerGallon(3.0);
    CHECK(gasoline.calculateCostOfTrip(20) == doctest::Approx(2.0));
}

TEST_CASE("Electric vehicle cost calculation with small trip distance") {
    Electric electric;
    electric.setMpge(100);
    electric.setCostPerkWh(0.1);
    CHECK(electric.calculateCostOfTrip(30) == doctest::Approx(0.03));
}





// g++ -o test_vehicle Vehicle.cpp Vehicle_unittests.cpp