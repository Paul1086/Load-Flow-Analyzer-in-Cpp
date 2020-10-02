#ifndef ComplexMatrixMATRIX_H
#define ComplexMatrixMATRIX_H


#include <iostream>
#include <math.h>
using namespace std;

class ComplexMatrix
{

public:

    double re, im;
    ComplexMatrix(): re(0), im(0)
    {
         //cout << "No argument constructor" << endl;
    }
    ComplexMatrix(double a, double b): re(a), im(b)
    {
         //cout << "Two argument constructor " << endl;
    }

    void set(double a, double b)
    {
        re = a;
        im = b;
    }

    void showvalue()
    {
        cout << "Value for real part is : " << re << endl;
        cout << "Value for imag part is : " << im << endl;
    }

    double mag()
    {
        return sqrt(re*re + im*im);
    }

    double ang()
    {
        return atan(im/re);
    }

    ComplexMatrix operator * (ComplexMatrix rhs)
    {
        return ComplexMatrix(re*rhs.re-im*rhs.im, re*rhs.im + im*rhs.re);
    }
    ComplexMatrix conjugate()
    {
        return ComplexMatrix(re, -im);
    }
    ComplexMatrix operator / (double rhs)
    {
        return ComplexMatrix(re/rhs, im/rhs);
    }
    ComplexMatrix operator / (ComplexMatrix rhs)
    {
        return (*this)*rhs.conjugate()/(rhs.mag()*rhs.mag());
    }
    void display()
    {
        cout << re << " + j " << im;
    }
    ComplexMatrix operator = (ComplexMatrix c)
    {
        ComplexMatrix t;
        re = c.re;
        im = c.im;
        return (*this);
    }
    ComplexMatrix operator + (ComplexMatrix c)
    {
        ComplexMatrix t;
        t.re = re + c.re;
        t.im = im + c.im;
        return t;
    }
    ComplexMatrix operator - (ComplexMatrix c)
    {
        ComplexMatrix t;
        t.re = re - c.re;
        t.im = im - c.im;
        return t;
    }
};

#endif // MYComplexMatrix_H
