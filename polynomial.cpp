#include "polynomial.h"
#include <sstream>
#include <iomanip>
#include <iostream>
using std::stringstream;
using std::showpos;
using std::fixed;
using std::setprecision;
/**
 Implement
 1. Constructors
 2. Destructor
 3. Copy Assignment Operator
 4. ToString
 5. Read and Write
 6. The rest  of the methods

*/

Polynomial::Polynomial(size_t degree){ // Constructor initializes a polynomial of a specified degree
    _degree = degree; //initializations
    _coefficients = new float[_degree]; // dynamically allocates an array
    for(size_t i = 0; i <= _degree; ++i){ // Loop through array to set coefficients to 0
        _coefficients[i] = 0.0;
    }
}
/**
*This Constructor takes a degree and an array of coefficients and initializes the polynomial
*with the given degree and coefficients
*/
Polynomial::Polynomial(size_t degree, const float* coefficients){
    _degree = degree; // initializations
    _coefficients = new float[_degree]; // dynamically allocates an array
    for (size_t i = 0; i <= _degree; ++i){ // Loop through array to set coefficients to given coefficients
        _coefficients[i] = coefficients[i];
    }
    }

// Copy Constructor creates a new Polynomial object that is a copy of another Polynomial object
Polynomial::Polynomial(const Polynomial& other){
    _degree = other._degree; // initializations
    _coefficients = new float[_degree]; // dynamically allocates an array
    for (size_t i = 0; i <= _degree; ++i){ // Loop through array to set coefficients equal to copy coefficients
        _coefficients[i] = other._coefficients[i];
    }
}

Polynomial::~Polynomial(){ // Destructor, deallocates the allocate memory
    delete[] _coefficients;
}

/*
 * Sum Function calculates the sum of two polynomials and returns a new Polynomials
 * object representing the result.
 */
const Polynomial Polynomial::Sum(const Polynomial& rhs)const{
    size_t totalDegree = std::max(_degree, rhs._degree);
    Polynomial result(totalDegree); // Object created to store result

    for(size_t i = 0; i <= totalDegree; ++i){ // Loop through coefficients up to total degree
        float coefficients1 = 0.0;
        //If the current index is within the degree of the first polynomial, update coefficients1
        if( i <= _degree) {
            coefficients1 = _coefficients[i];
        }
        float coefficients2 = 0.0;
        // If the current index is within the degree of the second polynomial, update coefficients2
        if( i <= rhs._degree){
            coefficients2 = rhs._coefficients[i];
        }
        // Calculate the sum of the coefficients and assign it to the corresponding index in the result polynomial
        result._coefficients[i] = coefficients1 + coefficients2;
    }
    // Return the resulting polynomial
    return result;
}
/*
 * Subtraction Function calculates the difference of two polynomials and returns a new Polynomials
 * object representing the result.
 */
const Polynomial Polynomial::Subtract(const Polynomial& rhs)const{
    size_t totalDegree = std::max(_degree, rhs._degree);
    Polynomial result(totalDegree); // Object created to store result

    for(size_t i = 0; i <= totalDegree; ++i){ // Loop through coefficients up to total degree
        float coefficients1 = 0.0;
        // If the current index is within the degree of the first polynomial, update coefficients1
        if( i <= _degree) {
            coefficients1 = _coefficients[i];
        }
        float coefficients2 = 0.0;
        // If the current index is within the degree of the second polynomial, update coefficients2
        if( i <= rhs._degree){
            coefficients2 = rhs._coefficients[i];
        }
        // Subtract the coefficients and assign it to the corresponding index in the result polynomial
        result._coefficients[i] = coefficients1 - coefficients2;
    }
    // Return the resulting polynomial
    return result;
}

 // Function to calculate the negation of Polynomials
const Polynomial Polynomial::Minus()const{
    Polynomial result(_degree);
    // Negate each coefficient of the polynomial
    for (size_t i = 0; i <= _degree; i++){
        result._coefficients[i] = -_coefficients[i];
    }
    // Return the resulting polynomial
    return result;
}
/*
 * Function calculates the product of two polynomials and returns a new Polynomials
 * object representing the result.
 */
const Polynomial Polynomial::Multiply(const Polynomial& rhs)const{
    size_t totalDegree = _degree + rhs._degree;
    Polynomial result(totalDegree);
    // Multiply each term of the first polynomial with each term of the second polynomial
    for (size_t i = 0; i <= _degree; i++){
        for (size_t j = 0; j <= rhs._degree; j++){
            result._coefficients[i+j] += _coefficients[i] * rhs._coefficients[j];
        }
    }
    // Return the resulting polynomial
    return result;
}

const Polynomial Polynomial::Divide(const Polynomial& rhs)const{
    return Polynomial(0);
}
const Polynomial Polynomial::Divide(const Polynomial& rhs, Polynomial& remainder)const{
    remainder = Polynomial(0);
    return Polynomial(0);
}

// Function that returns the derivative of the function
const Polynomial Polynomial::Derive()const{
    if(_degree == 0){
        return Polynomial(0);
    }
    Polynomial result(_degree - 1);
    // Calculate the derivative of each term of the polynomial
    for (size_t i = 1; i <= _degree; i++){
        result._coefficients[i-1] = i * _coefficients[i];
    }
    // Return the resulting polynomial
    return result;
}
// Function to evaluate the polynomial at a given value of x
float Polynomial::Evaluate(float x)const {
    float result = 0.0;
    // Evaluate the polynomial using Horner's method
    for (int i = _degree; i >= 0; i--){
        result = result * x + _coefficients[i];
    }
    // Return the result of the evaluation
    return result;
}

float Polynomial::Integrate(float start, float end)const{
    return 0.0;
}
// Assign operator used for assigning the polynomials
const Polynomial& Polynomial::operator=(const Polynomial& rhs){
    if(this == &rhs){
        return *this;
    }
    // Delete the existing coefficients array
    delete[] _coefficients;
    // Copy the degree and coefficients from the rhs polynomial
    _degree = rhs._degree;
    _coefficients = new float[_degree + 1];

    for (size_t i = 0; i <= _degree; i++){
        _coefficients[i] = rhs._coefficients[i];
    }
    return *this;
}
// Bool function to check if two polynomials are equal
bool Polynomial::Equals(const Polynomial& rhs)const{
    if(_degree != rhs._degree){
        return false;
    }
    for(size_t i = 0; i <= _degree; ++i){
        if (_coefficients[i] != rhs._coefficients[i]){
            return false;
        }
    }
    return true;
}
// ToString function to convert the polynomial to a string representation
string Polynomial::ToString()const{
    stringstream ss;
    for (size_t i = _degree; i > 0; i--) {
        ss << showpos << fixed << setprecision(2) << _coefficients[i] << "x^" << i << " ";
    }
    ss << showpos << fixed << setprecision(2) << _coefficients[0];
    return ss.str();
}
// Write function to write the polynomial to an output stream
ostream& Polynomial::Write(ostream& output)const{
    output << _degree << " ";
    for (size_t i = 0; i < _degree + 1; i++) {
        output << _coefficients[i] << " ";
    }
    return output;
}
// Read function read the polynomial from an input stream
istream& Polynomial::Read(istream& input){
    size_t degree;
    input >> degree;
    if (input.fail()){
        return input;
    }
    float* coefficients = new float[degree + 1];
    for (size_t i = 0; i < degree + 1; i++) {
        input >> coefficients[i];
        if (input.fail()){
            delete[] coefficients;
            return input;
        }
    }

    if (degree != _degree){
        if (_coefficients){
            delete[] _coefficients;
        }
        _degree = degree;
        _coefficients = coefficients;
    }else{
        for (size_t i = 0; i < _degree + 1; i++) {
            _coefficients[i] = coefficients[i];
        }
        delete[] coefficients;
    }
    return input;
}
