#ifndef _POINT_3D_H_
#define _POINT_3D_H_

#include <iostream>

using namespace std;

struct Point3d {
   
   private:
        double x;
        double y;
        double z;
   
   public:
    Point3d();
    Point3d(const Point3d & p3d);
    Point3d(double all);
    Point3d(double x, double y, double z);
    ~Point3d();

    double get_x() { return x; }
    double get_y() { return y; }
    double get_z() { return z; }

    void set_x(int x_in) { x = x_in; }
    void set_y(int y_in) { y = y_in; }
    void set_z(int z_in) { z = z_in; }


    void move_by(double offset_x, double offset_y, double offset_z) {
        x += offset_x;
        y += offset_y;
        z += offset_z;
    }
    Point3d operator-(const Point3d& rhs) const;
    Point3d cross(const Point3d& rhs) const;
    double magnitude() const;
};

#endif
