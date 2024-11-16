#include "CW15_1.h"
using namespace std;


void Rational::show() const {
    cout << nom << "/" << denom << "\n";
}


int Rational::input() {
    cout << "Input numerator: ";
    cin >> nom;
    cout << "Input denominator: ";
    cin >> denom;

    if (denom == 0) {
        cerr << "Denominator cannot be zero.\n";
        return -1;
    }

    reduce();
    return 0;
}


Rational Rational::add(const Rational& x) const {
    int t = nom * x.denom + denom * x.nom;
    unsigned y = denom * x.denom;
    return Rational(t, y);
}


Rational Rational::mull(const Rational& x) const {
    int t = nom * x.nom;
    unsigned y = denom * x.denom;
    return Rational(t, y);
}


bool Rational::less(const Rational& x) const {
    return (nom * x.denom < denom * x.nom);
}


double Rational::compare(double z) const {
    return fabs(z - static_cast<double>(nom) / denom);
}


unsigned Rational::gcd(unsigned x, unsigned y) {
    while (y != 0) {
        unsigned temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

void Rational::reduce() {
    unsigned nsd = gcd(abs(nom), denom);
    nom /= nsd;
    denom /= nsd;
}


#include "CW15_1.h"

Rational Hregory(double eps) {
    Rational s;     
    int sign = 1;     

    for (int i = 1;; i++) {
        Rational tmp(sign, i * i);  
        s = s.add(tmp);            


        sign = -sign;


        if (fabs(tmp.get_nom() * 1.0 / tmp.get_denom()) < eps) {
            break;
        }
    }

    return s;  
}


Rational min_rational(Rational *arr, int n) {
    Rational min_rat = arr[0];  
    for (int i = 1; i < n; i++) {
        if (!min_rat.less(arr[i])) {
            min_rat = arr[i];
        }
    }
    return min_rat;
}