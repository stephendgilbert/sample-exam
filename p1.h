#ifndef P1_H
#define P1_H

// Place your class definition here
// --------------------------------
#include <string>
#include <iostream>
class Point3D
{
public:
    Point3D();
    Point3D(double, double, double);
    double getX() const;
    double getY() const;
    double getZ() const;
    // double operator-(const Point3D&) const;

private:
    double x, y, z;
};

std::ostream& operator<<(std::ostream& out, const Point3D& p);

#endif
