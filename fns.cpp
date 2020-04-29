#include<iostream>
#include<cmath>
#include "lib.hpp"

//Default constructor with no arguments
Complex::Complex(){
	_real = 0, _imag = 0;
}
//Default constructor with arguments
Complex::Complex(double real, double imag){
	_real = real;
	_imag = imag;
}
//Copy constructor
//TODO: You need to change &Complex to something else, make sure it matches with what is in lib.hpp
Complex::Complex(const Complex &Complex){
	_real = Complex._real;
	_imag = Complex._imag;
}

double Complex::getreal(){
	return _real;
}

double Complex::getimag(){
	return _imag;
}

//TODO: Please consider the case when _imag is negative
void Complex::print(){
	std::cout << _real << " + " << _imag << "j" << std::endl;
}

Complex Complex::add(Complex c2){
	Complex c3;
	c3._real = getreal() + c2._real;
	c3._imag = getimag() + c2._imag;
	return c3;
	
}

Complex Complex::sub(Complex c2){			
	Complex c3;
	c3._real = getreal() - c2.getreal();
	c3._imag = getimag() - c2.getimag();
	return c3;
}

Complex Complex::mult(Complex c2){
	Complex c3;
	c3._real = getreal() * c2._real;
	c3._imag = getimag() * c2._imag;
	return c3;
}

//TODO: This is not the corret way of dividing two complex numbers
Complex::div(Complex c2){
	if(c2 == 0){
		return -1;
	}
	else{
		Complex c3;
		c3._real = getreal() / c2.getreal();
		c3._imag = getimag() / c2.getimag();
		return c3;
	}
}

//TODO: I'd replace c2 with c1
Complex Complex::conj(Complex c1){
	c2._imag = -c2._imag;
	return c2;
}

Complex Complex::magnitude(Complex c1){
	Complex c2(sqrt(c1._real * c1._real + c1._imag * c1._imag));
	return c2;
}

//TODO: This method should not return a Complex class, it should be a double
Complex Complex::phase(Complex c1){
	Complex c2 = atan(c1._real/c1.imag);
	return c2;
}

Complex Complex::operator-(Complex comp){
	Complex temp(sub(comp));
	return temp;
}

Complex Complex::operator+(Complex comp){
	Complex temp(add(comp));
	return temp;
}

Complex Complex::operator*(Complex comp){
	Complex temp(mult(comp));
	return temp;
}

Complex Complex::operator/(Complex comp){
	Complex temp(div(comp));
	return temp;
}

Complex Complex::operator=(Complex comp){
	_real = comp._real;
	_imag = comp._imag;	
	return *this;
}

//TODO: You no longer need the friend keyword here
friend std::ostream& operator<<(std::ostream &out, const Complex &c){
	if(c._imag = 0){
		out << c._real;
		return out;
	}
	else if(c._imag < 0){
		c._imag = conj(c._imag);
		out << c._real<< " - " << c._imag<< "j";
		return out;
	}
	else{
		out << c._real<< " + " << c._imag<< "j";
		return out;
	}
}
//TODO: You no longer need the friend keyword here
friend std::istream& operator>>(std::istream &in, Complex &c){
	in >>c._real>>c._imag;
	return in;
}
