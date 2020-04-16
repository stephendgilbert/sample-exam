/**
 * Basic unit tests for CS 150
 * @author Steve G.
 * @version UNIT TESTING FOR PE09 (Fall 2017)
 * This is the implementation file.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

#include "cs150check.h"

/**
 * Global variables for scoring points.
 */
int possible = 0;
int fail = 0;
static const string UNDERLINE(70,'-');

static int allPossible = 0;
static int allFail = 0;

void makeSnip(const string& code)
{
    ofstream out("a.cpp");
    out << "#include <string>\n#include <iostream>\n#include <sstream>\nusing namespace std;" << endl;
    out << "#include \"p1.h\"" << endl;
    out << "int main() {\n" << code << "\n}" << endl;
}
int syntaxCheck(const string& code)
{
    makeSnip(code);
    string cmd = "cat a.cpp | g++ -fsyntax-only -std=c++11 -x c++ - >> compile-errors.txt 2>&1";
    return system(cmd.c_str());
}
void checkSyntax(const Task& task)
{
    bool ok = syntaxCheck(task.code) == 0;
    if (ok) passMsg(task.task, task.points);
    else failMsg(task.task, task.points);
}

void _successReport(const string& msg)
{
    cerr << "   + " << msg << endl;
}

void _failReport(const string& msg, int pts)
{
	cerr << "   X " << msg << endl;
	fail += pts;
}

void failMsg(const string& msg, int pts)
{
    possible += pts;
    _failReport(msg, pts);
}

void passMsg(const string& msg, int pts) {
    possible += pts;
    _successReport(msg);
}

//////////// OVERLOADED VERSION OF ASSERT_EQUALS ///////////////////////
void _assertEquals(const string& msg, const string& expected, const string& actual)
{
    possible++;
    if (expected != actual)
    {
    	_failReportEquals(msg, expected, actual);
    }
    else
    	_successReport(msg + "->" + actual);
}

void _assertEquals(const string& msg, int expected, int actual)
{
    possible++;
    if (expected != actual)
    {
    	_failReportEquals(msg, expected, actual);
    }
    else
    	_successReport(msg);
}

string str(double n) {
    ostringstream out;
    out << fixed << setprecision(3);
    out << n;
    return out.str();
}
void _assertEquals(const string& msg, double a, double b)
{
    _assertEquals(msg, str(a), str(b));
}

void _assertTrue(bool cond, const string& msg)
{
    possible++;
    if (!cond)
    {
    	_failReport(msg + " should be true, but is false.");
    }
    else
    	_successReport(msg);
}

void _assertFalse(bool cond, const string& msg)
{
    possible++;
    if (cond)
    {
    	_failReport(msg + " should be false, but is true.");
    }
    else
    	_successReport(msg);
}

void beginTests()
{
    cerr << "TESTING " << ASSIGNMENT << "--" << STUDENT << endl;
    cerr << UNDERLINE << endl;
    allPossible = allFail = 0;
}

void beginFunctionTest(const string& functionName)
{
	possible = fail = 0;
    cerr << "Checking: " << functionName << " -------------------" << endl;
}

void endFunctionTest()
{
    cerr << UNDERLINE << endl << "  Tests passing "
        << (possible - fail) << "/" << possible
        << " ("
        << fixed << setprecision(0)
        << (static_cast<double>(possible - fail) / possible) * 100.0
        << "%)." << endl << endl;

    allPossible += possible;
    allFail += fail;
}

extern int PROBLEM_POINTS;
const string UL(65, '=');
void endTests()
{
	double percent = (static_cast<double>(allPossible - allFail) / allPossible) * 100.0;
    int score = PROBLEM_POINTS * percent / 100;
    cerr << UL << endl;
    cerr << "TOTAL POINTS: " << score << "/" << PROBLEM_POINTS << " (" << percent << "%)" << endl;
    cerr << UL << endl;
}

//// Code from cs150io.hxx
void replaceAll(string& str, const std::string& from, const std::string& to)
{
    if(from.empty()) return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

int ARGC = 0;
char ** ARGV = 0;

/**
 * Main file for all testing and regular running.
 * @param argc
 * @param argv
 * @return
 */
int main(int, char **)
{
    // TURN OFF ERROR REPORTING
    cout << "CHECKING YOUR CODE. PLEASE WAIT..." << endl << endl;

    streambuf * oldBuf = cerr.rdbuf();
    ofstream out("results.txt");
    cerr.rdbuf(out.rdbuf());
	runTests();

    out.close();
    cerr.rdbuf(oldBuf);

    system("cat results.txt");
    system("rm -f a.*");

	return 0;
}

int run()
{
    // Add your code here

    return 0;
}
string STUDENT = "Programming Exam 9";
string TESTFILE = "";
string ASSIGNMENT = "Point3D class";
