/**
*  @file Polynomial.h
*  @author Almozaini:Mazen:A00323488:csc34118
*  @version 1.0
*  @date 2014-06-09
*   Assignment #9 
*   due 2014-06-10
*  A Polynomial class file showing the methods for calculating a polynomial.
*/
/*
this header file is finished and working fine.
*/
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>
using std::vector;
using std::ostream;
typedef int base_type;
struct PolyNode;

class Polynomial
{
public:

    Polynomial();                           // default constructor


    Polynomial(const Polynomial& src);      // copy constructor
    Polynomial& operator=(Polynomial src);  // assignment operator
    virtual ~Polynomial();                  // destructor
    void swap(Polynomial& other);           // swap function


    int degree() const;
    /**<
    returns the degree of the polynomial.
    @return int the degree
    @param none
    */

   double getCoefficient(double power) const;
    /**<
    returns the coefficient of the x(power) term.
    @return int the coefficient
    @param pwr the power of the coefficient 
    */

    double evaluateAt(double x) const;
    /**<
    returns the value of the polynomial at x.
    @return int the value at x
    @param x the variable
    */

    void print() const;
    /**<
    print the polynomial to standard output
    @return void
    @param none
    */

    void setCoefficient(double newCoefficient, int pwr);
    /**<
    replaces the coefficient of the x(power) term with newCoefficient.
    @return void
    @param newCoefficient the new replaced coefficient
    @param pwr the power the coefficient is at
    */

    friend ostream& operator<<(ostream& out, const Polynomial& list);

private:
    PolyNode* head;
};

#endif