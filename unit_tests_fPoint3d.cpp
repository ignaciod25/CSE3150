#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Point3d.h"

TEST_CASE("Point 3D") {
  
  SUBCASE("Edge cases") {
    
    Point3d p3d;
    CHECK(0 == p3d.get_x());
    CHECK(0 == p3d.get_y());
    CHECK(0 == p3d.get_z());
    
    p3d.set_x(5);
    CHECK(5 == p3d.get_x());
    
    p3d.set_y(-3);
    CHECK(-3 == p3d.get_y());
    
    p3d.set_z(10);
    CHECK(10 == p3d.get_z());

    Point3d p3d2(2, 4, -7);
    CHECK(2 == p3d2.get_x());
    CHECK(4 == p3d2.get_y());
    CHECK(-7 == p3d2.get_z());
  };

  
  SUBCASE("Small cases") {
    Point3d p3d(1, 1, 1);
    CHECK(1 == p3d.get_x());
    CHECK(1 == p3d.get_y());
    CHECK(1 == p3d.get_z());

    p3d.move_by(2, -3, 5);
    CHECK(3 == p3d.get_x());
    CHECK(-2 == p3d.get_y());
    CHECK(6 == p3d.get_z());

    p3d.move_by(-3, 4, -2);
    CHECK(0 == p3d.get_x());
    CHECK(2 == p3d.get_y());
    CHECK(4 == p3d.get_z());
  };
}
