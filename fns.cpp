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
		//TODO: Please look at lib.hpp for what to do here, the body of the code looks good.
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

		//TODO: Complex c1 is not needed because you are using interal variables.
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

		//TODO: Here are you missing the Complex:: before conj
		Complex Complex::conj(Complex c1){
			c2._imag = -c2._imag;
			return c2;
		}

		//TODO: Here are you missing the Complex:: before magnitude
		Complex Complex::magnitude(Complex c1){
			Complex c2(sqrt(c1._real * c1._real + c1._imag * c1._imag));
			return c2;
		}

		//TODO: Here are you missing the Complex:: before phase
		Complex Complex::phase(Complex c1){
			Complex c2 = atan(c1._real/c1.imag);
			return c2;
		}

		//TODO: Here are you missing the Complex:: before operator-
		Complex Complex::operator-(Complex comp){
			Complex temp(sub(comp));
			return temp;
		}

		//TODO: Here are you missing the Complex:: before operator+
		Complex Complex::operator+(Complex comp){
			Complex temp(add(comp));
			return temp;
		}

		//TODO: Here are you missing the Complex:: before operator*
		Complex Complex::operator*(Complex comp){
			Complex temp(mult(comp));
			return temp;
		}

		//TODO: Here are you missing the Complex:: before operator/
		Complex Complex::operator/(Complex comp){
			//TODO: missing a '(' between 'div' and 'comp'
			Complex temp(div(comp));
			return temp;
		}

		//TODO: Here are you missing the Complex:: before operator=
		Complex Complex::operator=(Complex comp){
			_real = comp._real;
			_imag = comp._imag;	
			return *this;
		}

		friend std::ostream& operator<<(std::ostream &out, const Complex &c){
			if(c._imag = 0){
				out << c._real;
				return out;
			}
			else if(c._imag < 0){
				//TODO: need to consider the case when imaginary part is negative
				c._imag = conj(c._imag);
				out << c._real<< " - " << c._imag<< "j";
				return out;
			}
			else{
				out << c._real<< " + " << c._imag<< "j";
				return out;
			}
		}
		//TODO: operator<< should be operator>>
		friend std::istream& operator>>(std::istream &in, Complex &c){
			in >>c._real>>c._imag;
			return in;
		}
	}
