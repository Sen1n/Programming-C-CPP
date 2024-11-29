#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

namespace MyNamespace {
template <typename T>
T my_max(const T& a, const T& b) {
    return (a > b) ? a : b;
}
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
class Rational {
private:
    int numerator;
    int denominator;

    void simplify() {
        int gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Rational(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (den == 0) {
            throw std::invalid_argument("denominator cannot be zero");
        }
        simplify();
    }

    bool operator>(const Rational& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool operator==(const Rational& other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }

    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        os << r.numerator << "/" << r.denominator;
        return os;
    }
};

}

int main() {
    using namespace MyNamespace;
    int a = 5, b = 10;
    cout << "my_max of " << a << " and " << b << " is " << my_max(a, b) << endl;
    string str1 = "apple", str2 = "banan";
    cout << "my_max of \"" << str1 << "\" and \"" << str2 << "\" is \"" << my_max(str1, str2) << "\"" << endl;
    Rational r1(1, 2), r2(3, 4);
    cout << "my_max of " << r1 << " and " << r2 << " is " << my_max(r1, r2) << endl;
    // для раціонального дробу треба було довизначити оператор порівняння, щоб визначити який із дробів більший або менший
}
