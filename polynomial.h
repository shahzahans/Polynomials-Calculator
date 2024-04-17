#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <string>
using std::istream;
using std::ostream;
using std::string;

class Polynomial{
	size_t _degree;
	float* _coefficients;
public:
	Polynomial(size_t degree);
	Polynomial(size_t degree, const float* coefficients);
	Polynomial(const Polynomial& other);
	~Polynomial();
	const Polynomial Sum(const Polynomial& rhs)const;
	const Polynomial Subtract(const Polynomial& rhs)const;
	const Polynomial Minus()const;
	const Polynomial Multiply(const Polynomial& rhs)const;
	const Polynomial Divide(const Polynomial& rhs)const;
    const Polynomial Divide(const Polynomial& rhs, Polynomial& remainder)const;
	const Polynomial Derive()const;
	float Evaluate(float x)const;
	float Integrate(float a, float b)const;
	const Polynomial& operator=(const Polynomial& rhs);
	string ToString()const;
	bool Equals(const Polynomial& rhs)const;
	ostream& Write(ostream& output)const;
	istream& Read(istream& input);

};



#endif
