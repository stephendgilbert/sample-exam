/**
 *  @file tests.cpp
 *  @author Stephen Gilbert
 *  @version CS 150 Homework Testing
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

#include "cs150check.h"
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

int PROBLEM_POINTS = 50;
/**
 * Run your program's tests
 */
void runTests()
{
	///////////// Begin a set of tests
	beginTests(); // test heading

    beginFunctionTest("Point3D Definition (header file)");
    vector<Task> defTasks = {
        {"Working constructor defined.", "const Point3D r(10.0, 15.0, 100.0);", 2},
        {"Default constructor defined.", "const Point3D r;", 1},
        {"getX() accessor defined.", "const Point3D *r; r->getX();", 1},
        {"getX() return type correct.", "const Point3D * r;auto x = r->getX(); double& dr = x;", 1},
        {"getY() accessor defined.", "const Point3D * r;r->getY();", 1},
        {"getY() return type correct", "const Point3D * r;auto x = r->getY();double& dr = x;", 1},
        {"getZ() accessor defined", "const Point3D * r;r->getZ();", 1},
        {"getZ() return type correct", "const Point3D * r;auto x = r->getZ();double& dr = x;", 1},
        { "Overloaded operator-() defined.", "const Point3D *r1, *r2;auto r3=(*r1)-(*r2);",  1},
        {"Overloaded operator-() return type correct.", "const Point3D * r1, * r2;auto r3 = (*r1) - (*r2);double& r=r3;", 1},
        {"Overloaded output operator defined.", "const Point3D *r;ostringstream out;out << (*r);", 2},
    };
    for (auto task : defTasks)
    {
        checkSyntax(task);
    }

    endFunctionTest();
    /////// Tests for //////////////////////
	beginFunctionTest("Default constructor"); // function name

	// Test the constructor
	TEST_EQU(const Point3D p, "x initialized correctly", 0.0, p.getX())
	TEST_EQU(const Point3D p, "y initialized correctly", 0.0, p.getY())
	TEST_EQU(const Point3D p, "z initialized correctly", 0.0, p.getZ())

	endFunctionTest(); // end

	beginFunctionTest("Working constructor"); // function name

	// Test the constructor
	TEST_EQU(const Point3D p(1.5, 2, 3), "x initialized correctly", 1.5, p.getX())
	TEST_EQU(const Point3D p(5, 7.75, 9), "y initialized correctly", 7.75, p.getY())
	TEST_EQU(const Point3D p(2, 2, 2.5), "z initialized correctly", 2.5, p.getZ())

	endFunctionTest(); // end

	beginFunctionTest("Subtraction operator"); // function name

	// Test the constructor
	TEST_EQU(;, "Overloaded operator-()", 1.73205, (Point3D(1,1,1) - Point3D(2,2,2)))
	TEST_EQU(;, "Overloaded operator-()", 1.4142, (Point3D(1,0,1) - Point3D(2,0,2)))
	TEST_EQU(;, "Overloaded operator-()", 1.6401, (Point3D(1.2,2.3,3.4) - Point3D(2,2,2)))
	TEST_EQU(;, "Overloaded operator-()", 3.3166, (Point3D(0,0,0) - Point3D(1,1,3)))
	TEST_EQU(;, "Overloaded operator-()", 8.6603, (Point3D(5,5,5) - Point3D(0,0,0)))

	endFunctionTest(); // end
    
	beginFunctionTest("Output operator"); // function name

	// Test the constructor
	TEST_EQU(ostringstream out, "Overloaded operator<<", "Point3D(x->1.2, y->2.3, z->4.5)", (out << (Point3D(1.2,2.3,4.5)), out.str()))
	TEST_EQU(ostringstream out, "Overloaded operator<<", "Point3D(x->1.0, y->-1.0, z->3.0)", (out << (Point3D(1,-1,3)), out.str()))
	TEST_EQU(ostringstream out, "Overloaded operator<<", "Point3D(x->6.0, y->4.3, z->0.0)", (out << (Point3D(5.999, 4.256, .025)), out.str()))
	TEST_EQU(ostringstream out, "Overloaded operator<<", "Point3D(x->7.9, y->6.0, z->3.1)", (out << (Point3D(7.9,6,3.15)), out.str()))

	endFunctionTest(); // end
   ///////// End all test runs /////////////////////////
    endTests();

}


