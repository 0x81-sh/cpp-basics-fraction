#include "TEST.h"
#include "Fraction.h"

void testBaseFunctionality();
void testOperators();

int main() {
    testBaseFunctionality();
    testOperators();

    return 0;
}

void testBaseFunctionality() {
    T_UNIT("Base", "Set/Get/Reduce", {
        Fraction test(1, 1);
        test.setFraction(10, 5);

        T.EXPECT(test.getNumerator() == 2);
        T.EXPECT(test.getDenominator() == 1);
    })

    /* Compiles to:

    TEST::NamedUnit([](TEST::T &T) {
        Fraction test(1, 1);
        test.setFraction(10, 5);
        T.EXPECT(test.getNumerator() == 2);
        T.EXPECT(test.getDenominator() == 1);
    }, "Base", "Set/Get/Reduce");

    */
}

void testOperators() {
    T_UNIT("Operators", "Add", {
        Fraction result = Fraction(10, 27).add(Fraction(5, 13));
        T.EXPECT(result == Fraction(265, 351));

        T.EXPECT(Fraction(10, 27) + Fraction(5, 13) == Fraction(265, 351));
    })

    T_UNIT("Operators", "Subtract", {
        Fraction result = Fraction(10, 27).subtract(Fraction(5, 13));
        T.EXPECT(result == Fraction(-5, 351));

        T.EXPECT(Fraction(10, 27) - Fraction(5, 13) == Fraction(-5, 351));
    })

    T_UNIT("Operators", "Multiply", {
        Fraction result = Fraction(10, 28).multiply(Fraction(5, 14));
        T.EXPECT(result == Fraction(25, 196));

        T.EXPECT(Fraction(10, 28) * Fraction(5, 14) == Fraction(25, 196));
    })

    T_UNIT("Operators", "Divide", {
        Fraction result = Fraction(10, 28).divide(Fraction(5, 14));
        T.EXPECT(result == Fraction(1, 1));

        T.EXPECT(Fraction(10, 28) / Fraction(5, 14) == Fraction(1, 1));
    })
}