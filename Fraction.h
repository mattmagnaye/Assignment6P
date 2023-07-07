/*
* Program: Fraction.h (Assignment 6P: Objects & Classes 2)
* Author: Matt Aaron Magnaye
* Instructor: Professor David Harden
* Date: 07/06/2023
* Description: Fraction class represents a mathematical fraction with a numerator and denominator.
*
*/
#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify();

public:
    Fraction();
    Fraction(int numerator, int denominator);

    Fraction addedTo(const Fraction& other) const;
    Fraction subtract(const Fraction& other) const;
    Fraction multipliedBy(const Fraction& other) const;
    Fraction dividedBy(const Fraction& other) const;
    bool isEqualTo(const Fraction& other) const;

    void print() const;
};

#endif

