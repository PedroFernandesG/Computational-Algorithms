#include <iostream>
#include <cmath>

#ifndef COMPLEX
#define COMPLEX

class Complex{
    private:
        float real, imag;
    public:
        Complex(float = 0, float = 0);
        ~Complex(){}
        Complex add(Complex&);
        Complex sub(Complex&);

        //Operator Overloading
        friend Complex operator+(const Complex& a, const Complex& b);
        friend std::ostream& operator<<(std::ostream& out, const Complex& c);
        friend std::istream& operator>>(std::istream&in, Complex& c);
        operator int();
        /*  Implicit:: operator int();  int num = complexNumber
            Explicit:: explicit operator int(); int num = (int)complexNumber
        */
        Complex operator-(Complex&);
   
};
#endif