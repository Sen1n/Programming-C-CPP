#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

class Point {
    static int count; 
    double x;
    double y;

public:
    Point() {
        x = 0;
        y = 0;
        count++;
    }

    ~Point() {
        count--;
    }

    void input_point() {
        cout << "Enter x, y: ";
        cin >> x >> y;

        while (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter valid x, y: ";
            cin >> x >> y;
        }
    }

    static int counter() {
        return count;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }
};

int Point::count = 0;

double length(const Point& a, const Point& b) {
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

int main() {
    const int MAX_VERTICES = 100;
    Point vertices[MAX_VERTICES];
    int i = 0;
    char answer;
    int entered_points = 0;  // Лічильник введених точок

    do {
        cout << "Input vertex? (y/n): ";
        cin >> answer;

        while (cin.fail() || (answer != 'y' && answer != 'n')) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin >> answer;
        }

        if (answer == 'n') {
            break;
        }

        if (i >= MAX_VERTICES) {
            cout << "Maximum number of vertices reached!" << endl;
            break;
        }

        vertices[i].input_point();
        entered_points++;  // Інкрементуємо лічильник введених точок
        i++;
    } while (true);

    cout << "\nNumber of points entered: " << entered_points << endl;  // Виводимо кількість введених точок

    double perimeter = 0;
    for (int j = 1; j < i; j++) {
        perimeter += length(vertices[j], vertices[j - 1]);
    }
    if (i > 2) {
        perimeter += length(vertices[i - 1], vertices[0]);
    }

    cout << "Perimeter of the polygon: " << perimeter << endl;

    return 0;
}
