#include <iostream>

#ifndef COMPLEX
#define COMPLEX

class Complex{
   private:
      float real, imag;
   public:
      Complex(float = 0;float = 0);
      ~Complex(){}//In-line

      void print();
      Complex add(Complex&);
      Complex sub(Complex&);

      //Operator Overloading 
      Complex operator+(Complex&);
      Complex& operator++(); //Pre
      Complex operator++(int);//Pos
      Complex operator-(Complex&)
      bool operator!();
};

#endif
