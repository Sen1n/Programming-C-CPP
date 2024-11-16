#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

class Polynom {
private:
    int N;          // Кількість коефіцієнтів
    double* coeffs; // Масив коефіцієнтів

public:

    Polynom() : N(0), coeffs(nullptr) {}

    Polynom(int n) : N(n) {
        if (N <= 0) {
            throw invalid_argument("Degree must be greater than 0");
        }
        coeffs = new double[N]();
    }

    Polynom(const Polynom& other) : N(other.N) {
        coeffs = new double[N];
        for (int i = 0; i < N; ++i) {
            coeffs[i] = other.coeffs[i];
        }
    }

    ~Polynom() {
        delete[] coeffs;
    }

    Polynom& operator=(const Polynom& other) {
        if (this != &other) {
            delete[] coeffs;

            N = other.N;
            coeffs = new double[N];
            for (int i = 0; i < N; ++i) {
                coeffs[i] = other.coeffs[i];
            }
        }
        return *this;
    }


    void set_coeff(int index, double value) {
        if (index < 0 || index >= N) {
            throw out_of_range("Index out of range");
        }
        coeffs[index] = value;
    }

    double get_coeff(int index) const {
        if (index < 0 || index >= N) {
            throw out_of_range("Index out of range");
        }
        return coeffs[index];
    }

    void display() const {
        for (int i = 0; i < N; ++i) {
            if (coeffs[i] != 0) {
                cout << coeffs[i] << "x^" << i;
                if (i != N - 1) {
                    cout << " + ";
                }
            }
        }
        cout << endl;
    }

    friend ostream& operator<<(ostream& os, const Polynom& p) {
        for (int i = 0; i < p.N; ++i) {
            os << p.coeffs[i] << " ";
        }
        return os;
    }

    friend istream& operator>>(istream& is, Polynom& p) {
        for (int i = 0; i < p.N; ++i) {
            is >> p.coeffs[i];
        }
        return is;
    }

    friend void save_to_file(const Polynom& p, const string& filename) {
        ofstream file(filename, ios::binary);
        if (!file) {
            throw runtime_error("Unable to open file");
        }
        file.write(reinterpret_cast<const char*>(&p.N), sizeof(p.N));
        file.write(reinterpret_cast<const char*>(p.coeffs), p.N * sizeof(double));
        file.close();
    }

    friend void load_from_file(Polynom& p, const string& filename) {
        ifstream file(filename, ios::binary);
        if (!file) {
            throw runtime_error("Unable to open file");
        }
        file.read(reinterpret_cast<char*>(&p.N), sizeof(p.N));
        delete[] p.coeffs;
        p.coeffs = new double[p.N];
        file.read(reinterpret_cast<char*>(p.coeffs), p.N * sizeof(double));
        file.close();
    }
};

int main() {
    try {
        Polynom p(3); // Поліном 2-го степеня (3 коефіцієнти)
        p.set_coeff(0, 1.0); // 1
        p.set_coeff(1, -2.0); // -2x
        p.set_coeff(2, 3.0); // 3x^2
        p.display();


        save_to_file(p, "polynom.bin");


        Polynom p2;
        load_from_file(p2, "polynom.bin");

        cout << "Loaded polynom: ";
        p2.display();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
