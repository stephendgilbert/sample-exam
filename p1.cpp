#include <cmath>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
#include "p1.h"

// Implement your member functions in this file

Point3D::Point3D() : x(0), y(0), z(0) {}
Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
// double Point3D::getX() const { return x; }
// double Point3D::getY() const { return y; }
// double Point3D::getZ() const { return z; }
// double Point3D::operator-(const Point3D& p2) const
// {
//     double xd = getX() - p2.getX();
//     double yd = getY() - p2.getY();
//     double zd = getZ() - p2.getZ();

//     return sqrt(xd * xd + yd * yd + zd * zd);
//     return 0;
// }

ostream& operator<<(ostream& out, const Point3D& p)
{
    out << fixed << setprecision(1);
    out << "Point3D(x->" << p.getX() << ", y->" << p.getY()
        << ", z->" << p.getZ() << ")";
    return out;
}
