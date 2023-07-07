/*
* Program: Fraction.cpp (Assignment 6P: Objects & Classes 2)
* Author: Matt Aaron Magnaye
* Instructor: Professor David Harden
* Date: 07/06/2023
* Description: Implements the member functions of the 'Fraction' class.
*
*/
#include "Fraction.h"
#include <iostream>
#include <cassert>

using namespace std;

// Default constructor initializes the fraction 0/1.
Fraction::Fraction() : numerator(0), denominator(1) {}

// Parameterized constructor initializes the fraction with the given numerator and denominator.
Fraction::Fraction(int numerator, int denominator) {
    assert(denominator != 0);
    this->numerator = numerator;
    this->denominator = denominator;
    simplify();
}

// Reduces the fraction to its simplest form by finding the greatest common divisor (GCD).
void Fraction::simplify() {
    if (numerator != 0) {
        int commonDivisor = 1;
        int absNumerator = abs(numerator);
        int absDenominator = abs(denominator);
        int smallerValue = (absNumerator < absDenominator) ? absNumerator : absDenominator;

        for (int i = 2; i <= smallerValue; i++) {
            if (absNumerator % i == 0 && absDenominator % i == 0) {
                commonDivisor = i;
            }
        }

        numerator /= commonDivisor;
        denominator /= commonDivisor;
    }
}

// Adds the given fraction to the current fraction.
Fraction Fraction::addedTo(const Fraction& other) const {
    int resultNumerator = (numerator * other.denominator) + (other.numerator * denominator);
    int resultDenominator = denominator * other.denominator;
    return Fraction(resultNumerator, resultDenominator);
}

// Subtracts the given fraction from the current fraction.
Fraction Fraction::subtract(const Fraction& other) const {
    int resultNumerator = (numerator * other.denominator) - (other.numerator * denominator);
    int resultDenominator = denominator * other.denominator;
    return Fraction(resultNumerator, resultDenominator);
}

// Multiplies the current fraction by the given fraction.
Fraction Fraction::multipliedBy(const Fraction& other) const {
    int resultNumerator = numerator * other.numerator;
    int resultDenominator = denominator * other.denominator;
    return Fraction(resultNumerator, resultDenominator);
}

// Divides the current fraction by the given fraction.
Fraction Fraction::dividedBy(const Fraction& other) const {
    int resultNumerator = numerator * other.denominator;
    int resultDenominator = denominator * other.numerator;
    return Fraction(resultNumerator, resultDenominator);
}

// Checks if the current fraction is equal to the given fraction.
bool Fraction::isEqualTo(const Fraction& other) const {
    return (numerator * other.denominator) == (denominator * other.numerator);
}

// Prints the fraction in the format "numerator/denominator".
void Fraction::print() const {
    cout << numerator << "/" << denominator;
}
