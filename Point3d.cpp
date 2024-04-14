#include <iostream>
#include <cmath>


#include "Point3d.h"

using namespace std;



std::ostream & operator<<(std::ostream &os, Point3d & p3d)
{
    
    os << " x = " << p3d.get_x() 
       << " y = " << p3d.get_y() 
       << " z = " << p3d.get_z();

    return os;
};

// Implementation of operator-
Point3d Point3d::operator-(const Point3d& rhs) const {
    return Point3d(x - rhs.x, y - rhs.y, z - rhs.z);
}

// Implementation of cross product
Point3d Point3d::cross(const Point3d& rhs) const {
    return Point3d(
        y * rhs.z - z * rhs.y,
        z * rhs.x - x * rhs.z,
        x * rhs.y - y * rhs.x
    );
}

// Implementation of magnitude
double Point3d::magnitude() const {
    return sqrt(x * x + y * y + z * z);
}


Point3d::Point3d() : x(0.0), y(0.0), z(0.0) {};
Point3d::Point3d(double all) : x(all), y(all), z(all) {};
Point3d::Point3d(const Point3d & p3d) : x(p3d.x), y(p3d.y), z(p3d.z) {};
Point3d::Point3d(double x, double y, double z) :  x(x), y(y), z(z) {};
Point3d::~Point3d() {};