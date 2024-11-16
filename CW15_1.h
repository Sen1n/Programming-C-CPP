#pragma once
#include <iostream>
#include <cmath>
#include <vector>

class Rational {
private:
    int nom;       // Чисельник
    unsigned denom; // Знаменник

    void reduce(); // Скорочення дробу до найпростішої форми

public:
    // Конструктори
    Rational() : nom(0), denom(1) {} // Значення за замовчуванням: 0/1
    Rational(int x, unsigned y) : nom(x), denom(y) {
        if (denom == 0) throw std::invalid_argument("Denominator cannot be zero");
        reduce();
    }

    // Методи
    void show() const;           // Показати раціональне число
    int input();                 // Введення раціонального числа
    Rational add(const Rational& x) const; // Додавання
    Rational mull(const Rational& x) const; // Множення
    bool less(const Rational& x) const;    // Порівняння: this < x ?
    double compare(double z) const;        // Порівняння з числом double

    // Гетери і Сетери
    int get_nom() const { return nom; }
    unsigned get_denom() const { return denom; }
    void set_nom(int x) { nom = x; }
    void set_denom(unsigned y) {
        if (y == 0) throw std::invalid_argument("Denominator cannot be zero");
        denom = y;
    }

    static unsigned gcd(unsigned x, unsigned y);
};


Rational find_min(const std::vector<Rational>& arr);
