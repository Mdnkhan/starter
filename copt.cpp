#include <iostream>
#include "Copt.h"

using namespace sakib_complex;
using namespace std;

//sets the numbers for the constructor
// function called inside constructor
void complex::set_number(double real, double imag) {
	real_part = real;
	imag_part = imag;
}

//access the private numbers for sum and sub function which are non-member
double complex::get_real()const {return real_part;}

double complex::get_imag()const {return imag_part;}



//ASSIGNMENT/COMBINE OPERATOR overloading function-----------------------------
complex& sakib_complex::complex::operator+=(const complex & added) //operator += override 
{
	this->real_part += added.get_real();
	this->imag_part += added.get_imag();

	return *this;
}

complex & sakib_complex::complex::operator-=(const complex & added)
{
	this->real_part -= added.get_real();
	this->imag_part -= added.get_imag();

	return *this;
}

bool sakib_complex::operator==(const complex & a, const complex & b)
{
	bool one = (a.get_real() == b.get_real());
	bool two = (a.get_imag() == b.get_imag());

	return (one && two);
}

//IOSTREAM operator override functions----------------------------------------
std::ostream & sakib_complex::operator<<(std::ostream & outs, const complex & b)
{
	
		if (b.get_imag() >= 0) {
			outs << b.get_real() << " + " << b.get_imag() << "i";
		}
		else {
			outs << b.get_real() << b.get_imag() << "i";
		}
		return outs;
}

std::istream & sakib_complex::operator>>(std::istream & outs, complex & b)
{
	double x;
	double y;
	outs >> x>>y;
	b.set_number(x,y);
	return outs;
}
//MATH operatior overloading function-------------------------------------
complex sakib_complex::operator-(const complex & a, const complex & b) //operator '-' override
{
	double real = a.get_real() - b.get_real();
	double imag = a.get_imag() - b.get_imag();

	complex result(real, imag);
	return result;
	
}

complex sakib_complex::operator+(const complex & a, const complex & b)//operator '+' override
{
	double real = a.get_real() + b.get_real();
	double imag = a.get_imag() + b.get_imag();

	complex sum(real, imag);
	return sum;
};


