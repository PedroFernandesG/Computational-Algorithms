#include "ComplexFriend.h"

using namespace std;

Complex operator+(const Complex& a, const Complex& b) {
    return Complex{a.real + b.real, a.imag + b.imag};
}

std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << c.real << " + (" << c.imag << ")i";
    return out;
}
std::istream& operator>>(std::istream&in, Complex& c){
    in >> c.real >> c.imag;
    return in;
}
Complex::Complex(float real, float imag){
    this->real = real;
    this->imag = imag;
}

Complex Complex::add(Complex& par){
    return Complex{this->real + par.real,this->imag + par.imag};
}
Complex Complex::sub(Complex& par){
    return Complex{this->real - par.real,this->imag - par.imag};
}

Complex Complex::operator-(Complex& par){
    return Complex{this->real - par.real,this->imag - par.imag};
}
Complex::operator int(){
    return sqrt(pow(real,2) + pow(imag,2));
}
