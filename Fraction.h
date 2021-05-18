#pragma once

class Fraction {
private:
    int num;
    int denom;

    void checkSign();
    void reduce();

public:
    Fraction(int num, int denom);
    int setFraction(int num, int denom);
    int getNumerator() const;
    int getDenominator() const;
    void showFraction() const;

    Fraction add(const Fraction &f) const;
    Fraction subtract(const Fraction &f) const;
    Fraction multiply(const Fraction &f) const;
    Fraction divide(const Fraction &f) const;
    Fraction operator+ (const Fraction &f) const;
    Fraction operator- (const Fraction &f) const;
    Fraction operator* (const Fraction &f) const;
    Fraction operator/ (const Fraction &f) const;

    bool operator== (const Fraction &f) const;
};

