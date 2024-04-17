#include "polynomial.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using std::cout;
using std::cerr;
using std::endl;
using std::left;
using std::setw;
using std::stringstream;

int Test(bool condition, const char *message);
bool DoubleEquals(double a, double b, double epsilon = 1e-6);

/**
 *      -----------------------
 *      DO NOT MODIFY THIS FILE
 *      -----------------------
 */


int main(int argc, char *argv[]) {
    const auto TOTAL_BASE_TESTS = 13.0;
    /**
     * Setting an array of stringstream to hold the values
     * to be used in the Polynomials.
     * The stream starts with the degree of the polynomial
     * followed by the values of the coefficients
     */
    stringstream data[5];
    data[0].str("3 -1 2 0 -2.5");
    data[1].str("4 -1 -2 0 0 3");
    data[2].str("2 -1 0 4");
    data[3].str("3 -6 -5 2 1");
    data[4].str("1 -2 1");
    /**
     * This array holds the values of the polynomials that
     * represent the expected answers to the operations below
     */
    stringstream answers[8];
    answers[0].str("4 -2 0 0 -2.5 3"); // a + b
    answers[1].str("7 1 0 -4 2.5 2 6 0 -7.5"); // a * b
    answers[2].str("2 3 4 1"); // d / e
    answers[3].str("2 1 0 -4"); // -c
    answers[4].str("4 0 -4 0 2.5 3"); // b - a
    answers[5].str("2 2 0 -7.5"); // d/dx a
    answers[6].str("1 0 -0.625"); // a / c quotient
    answers[7].str("1 -1 1.375"); // a % c reminder

    // Test Constructors
    float hData[] = {1, -1, 0, 3};
    Polynomial f(0),g(2),h(3, hData), k(h);
    Test(f.ToString() == "+0.00", "Constructor, degree=0");
    Test(g.ToString() == "+0.00x^2 +0.00x^1 +0.00", "Constructor, degree=2");
    Test(h.ToString() == "+3.00x^3 +0.00x^2 -1.00x^1 +1.00", "Constructor, degree=3, w/Array");
    Test(k.ToString() == "+3.00x^3 +0.00x^2 -1.00x^1 +1.00", "Copy Constructor");

    /**
     * Polynomials to use:
     * a = -2.50x^3 +0.00x^2 +2.00x^1 -1.00
     * b = +3.00x^4 +0.00x^3 +0.00x^2 -2.00x^1 -1.00
     * c = +4.00x^2 +0.00x^1 -1.00
     * d = +1.00x^3 +2.00x^2 -5.00x^1 -6.00
     * e = +1.00x^1 -2.00
     * r = +0.00
     */
    Polynomial a(0), b(0), c(0), d(3), e(1), r(0);

    // Test Read and Write
    a.Read(data[0]);
    Test(a.ToString() == "-2.50x^3 +0.00x^2 +2.00x^1 -1.00", "Read/ToString");
    stringstream out;
    a.Write(out);
    Test(out.str() == "3 -1 2 0 -2.5 ", "Write");
    b.Read(data[1]);
    c.Read(data[2]);
    d.Read(data[3]);
    e.Read(data[4]);

    /**
     * These polynomials will hold the expected
     * answers for the operations to test
     */
    Polynomial s(0), t(0), u(0), v(0), w(0), x(0), dq(0), dr(0);
    s.Read(answers[0]);
    t.Read(answers[1]);
    u.Read(answers[2]);
    v.Read(answers[3]);
    w.Read(answers[4]);
    x.Read(answers[5]);
    dq.Read(answers[6]);
    dr.Read(answers[7]);

    int total;

    Test(a.Sum(b).Equals(s), "Sum");
    Test(b.Subtract(a).Equals(w), "Subtract");
    Test(c.Minus().Equals(v), "Minus");
    Test(a.Multiply(b).Equals(t), "Multiplication");
    Test(a.Derive().Equals(x), "Derivation");
    Test(DoubleEquals(b.Evaluate(3.0),236.00), "Evaluation");
    f = a.Sum(b);
    total = Test(f.Equals(s), "Copy Assignment Operator");

    cout << "Base Grade Tests Finished - - - - - - - - - - - - - - - - - - " << endl;
    cerr << (total / TOTAL_BASE_TESTS * 100) << endl;
    Test(a.Integrate(1, 2)== -7.375, "Integration");
    Test(d.Divide(e).Equals(u), "Long Division");
    Polynomial remainder(0);
    Test(a.Divide(c, remainder).Equals(dq), "Long Division Quotient");
    total = Test(dr.Equals(remainder), "Long Division Reminder");
    cout << "Extra Credit Tests Finished - - - - - - - - - - - - - - - - - " << endl;
    cout << "UNIT TEST FINAL GRADE = " << (total / 13.0 * 100) << endl;
    cerr << (total / TOTAL_BASE_TESTS * 100) << endl;

    return 0;
}


int Test(bool condition, const char *message) {
    static auto passedTests = 0;
    if (condition) {
        cout << "TEST PASSED (" << left << setw(50) << message << ") Total Passed: " << ++passedTests << endl;
    } else {
        cout << "TEST FAILED (" << left << setw(50) << message << ") **************" << endl;
    }
    return passedTests;
}
bool DoubleEquals(double a, double b, double epsilon){
    return abs(a - b) < epsilon;
}