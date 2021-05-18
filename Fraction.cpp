#include "Fraction.h"
#include <iostream>

int gcd (int a, int b);
int lcm (int a, int b);

void Fraction::checkSign() {
    if (denom >= 0) return;

    num = -num;
    denom = -denom;
}

void Fraction::reduce() {
    int gcdV = gcd(abs(num), denom);
    if (gcdV == 1) return;

    num /= gcdV;
    denom /= gcdV;
}

Fraction::Fraction(int num, int denom) {
    if (!setFraction(num, denom)) {
        this->num = 0;
        this->denom = 1;
    }
}

int Fraction::setFraction(int num, int denom) {
    if (!denom) {
        std::cerr << "Invalid denominator. Canceled." << std::endl;
        return 0;
    }

    this->num = num;
    this->denom = denom;

    this->checkSign();
    this->reduce();

    return 1;
}

int Fraction::getNumerator() const {
    return num;
}

int Fraction::getDenominator() const {
    return denom;
}

void Fraction::showFraction() const {
    std::cout << num << "/" << denom;
}

Fraction Fraction::add(const Fraction &f) const {
    int lcmV = lcm(denom, f.denom);
    return Fraction((num * lcmV / denom) + (f.num * lcmV / f.denom), lcmV);
}

Fraction Fraction::subtract(const Fraction &f) const {
    int lcmV = lcm(denom, f.denom);
    return Fraction((num * lcmV / denom) - (f.num * lcmV / f.denom), lcmV);
}

Fraction Fraction::multiply(const Fraction &f) const {
    return Fraction(num * f.num, denom * f.denom);
}

Fraction Fraction::divide(const Fraction &f) const {
    return Fraction(num * f.denom, denom * f.num);
}


Fraction Fraction::operator+(const Fraction &f) const {
    return add(f);
}

Fraction Fraction::operator-(const Fraction &f) const {
    return subtract(f);
}

Fraction Fraction::operator*(const Fraction &f) const {
    return multiply(f);
}

Fraction Fraction::operator/(const Fraction &f) const {
    return divide(f);
}

bool Fraction::operator==(const Fraction &f) const {
    return num == f.num && denom == f.denom;
}

//--------------------------------------------

int gcd (int a, int b) {
    if (a == b) return a;

    if (a > b) {
        return gcd(a - b, b);
    } else {
        return gcd(b - a, a);
    }
}

int lcm (int a, int b) {
    return abs(a / gcd(a, b) * b);
}