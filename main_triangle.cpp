#include <iostream>
#include "Triangle3d.h"

using namespace std;

int main() {
    Point3d p1(0.0, 0.0, 0.0);
    Point3d p2(1.0, 2.0, 0.0);
    Point3d p3(-1.0, 0.0, 0.0);

    Triangle3d triangle(p1, p2, p3);
    
    // Print the area of the triangle
    cout << "The area is: " << triangle.area() << endl;

    return 0;
}
