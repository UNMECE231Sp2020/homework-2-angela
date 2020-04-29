#include<iostream>
#include<cmath>

class Complex{
	private:
		double _real;
		double _imag;
	public:
		//Default constructor with no arguments
		Complex();
		//Default constructor with arguments
		Complex(double real, double imag);
		//Copy constructor

		//TODO: You need to change &Complex to some other name, maybe c?
		Complex(const Complex &/**/Complex/**/);
		~Complex();

		double getreal();
		double getimag();

		void print(Complex c1);
		
		Complex add(Complex c2);
		Complex sub(Complex c2);			
		Complex mult(Complex c2);
		Complex div(Complex c2);
		Complex conj(Complex c1);
		Complex magnitude(Complex c1);
		Complex phase(Complex c1);

		Complex operator-(Complex comp);
		Complex operator+(Complex comp);
		Complex operator*(Complex comp);
		Complex operator/(Complex comp);
		Complex operator=(Complex comp);

		friend std::ostream& operator<<(std::ostream &out, const Complex &c);
		friend std::istream& operator>>(std::istream &in, Complex &c);
};
