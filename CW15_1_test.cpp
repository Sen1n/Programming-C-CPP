#include "CW15_1.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
     Rational r1(3, 4), r2(5, 6), r3(7, 8);
    
    std::cout << "Rational numbers:\n";
    r1.show();
    r2.show();
    r3.show();

    Rational r4 = r1.add(r2);
    Rational r5 = r1.mull(r3);
    std::cout << "Addition result:\n";
    r4.show();
    std::cout << "Multiplication result:\n";
    r5.show();

    Rational arr[] = {r1, r2, r3};
    Rational max_rat = min_rational(arr, 3);
    std::cout << "minimum rational number:\n";
    max_rat.show();


    double eps = 0.01;
        Rational approx = Hregory(eps);

        cout << "Approximation of pi^2 / 12 with epsilon " << eps << ": ";
        approx.show();
        cout << "Decimal value: " << static_cast<double>(approx.get_nom()) / approx.get_denom() << "\n";

}


