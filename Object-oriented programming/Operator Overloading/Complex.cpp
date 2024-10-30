#include "Complex.h"
#include <iostream>

using namespace std;

Complex::Complex(float real, float imag){
  this->real = real;
  this->imag = imag;
}
void Complex::print(){
    cout << real << "+ (" << imag << ")i" << endl;
}
Complex Complex::add(Complex& pair){
    return Complex{this->real + pair.real,this->imag + pair.imag};
}
Complex Complex::sub(Complex& pair){
    return Complex{this->real - pair.real,this->imag - pair.imag};
}
Complex Complex::operator+(Complex& pair){
    return Complex{this->real + pair.real,this->imag + pair.imag};
}
Complex Complex::operator-(Complex& pair){
    return Complex{this->real - pair.real,this->imag - pair.imag};
}
bool Complex::operator!(){
  if(real == 0 && imag == 0) return 1;

  return 0;
}
Complex& Complex::operator++(){//Pre

  this->real += 1;
  this->imag += 1;

  return *this;
}
Complex Complex::operator++(int value){//Pos
    Complex temp = *this;
    this->real += 1;
    this->imag += 1;

    return temp;
} 
