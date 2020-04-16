#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Point3D
{
public:
    Point3D();
    Point3D(double, double, double);
    double getX() const;
    double getY() const;
    double getZ() const;
    double operator-(const Point3D&) const;
// Note public
    double x, y, z;
};

std::ostream& operator<<(std::ostream&, const Point3D&);

struct NotImplemented : runtime_error {
    NotImplemented(const string& msg) : runtime_error(msg) { }
};

Point3D::Point3D() {throw NotImplemented("Not implemented: Point3D()");}
Point3D::Point3D(double, double, double) {throw NotImplemented("Not implemented: Point3D(double, double, double)");}
double Point3D::getX() const { throw NotImplemented("Not implemented: getX()"); }
double Point3D::getY() const { throw NotImplemented("Not implemented: getY()"); }
double Point3D::getZ() const {  throw NotImplemented("Not implemented: getZ()");}
double Point3D::operator-(const Point3D&) const
{
    throw NotImplemented("Not implemented: operator-()");
}

ostream& operator<<(ostream&, const Point3D&)
{
    throw NotImplemented("Not implemented: operator<<()");
}
