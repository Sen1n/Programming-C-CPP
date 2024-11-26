#include <iostream>
#include <cmath>

using namespace std;


class Point {
protected:
    double x, y;
    int dimension; 

public:

    Point() : x(0), y(0), dimension(2) {}


    Point(double x, double y) : x(x), y(y), dimension(2) {}


    void input() {
        cout << "Enter coordinates x and y: ";
        cin >> x >> y;
    }

    // show point coordinates
    void show() const {
        cout << "(" << x << ", " << y << ")";
    }

    // getter for x
    double getX() const { return x; }

    // getter for y
    double getY() const { return y; }

    //distance between two points
    double distanceTo(const Point& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }


    int getDimension() const {
        return dimension;
    }
};


class Point3D : public Point {
private:
    double z;

public:
    Point3D(double x = 0, double y = 0, double z = 0) : Point(x, y), z(z) {
        dimension = 3;
    }

    //input 3D point coordinates
    void input() {
        cout << "Enter coordinates x, y, and z: ";
        cin >> x >> y >> z;
    }

    //show 3D point coordinates
    void show() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }

    // getter for z
    double getZ() const { return z; }

    // Method to calculate the distance between two 3D points
    double distanceTo(const Point3D& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
    }
};


class Segment {
private:
    Point p1, p2; // For 2D points
    Point3D p1_3D, p2_3D; // for 3D points
    bool is3D; // To check if the segment is 3D or 2D

public:
    // constructor for 2D segment
    Segment(Point a, Point b) : p1(a), p2(b), is3D(false) {}

    // constructor for 3D segment
    Segment(Point3D a, Point3D b) : p1_3D(a), p2_3D(b), is3D(true) {}


    double length() const {
        if (is3D) {
            return p1_3D.distanceTo(p2_3D); // calculate length for 3D segment
        } else {
            return p1.distanceTo(p2); // calculate length for 2D segment
        }
    }

    // method to check if two segments intersect 
    static bool checkIntersection(Segment& a, Segment& b) {
        if (a.is3D || b.is3D) {
            cout << "Intersection check is not implemented for 3D segments." << endl;
            return false;
        }

        // Using getters for x and y to access the coordinates
        double x1 = a.p1.getX(), y1 = a.p1.getY();
        double x2 = a.p2.getX(), y2 = a.p2.getY();
        double x3 = b.p1.getX(), y3 = b.p1.getY();
        double x4 = b.p2.getX(), y4 = b.p2.getY();

        double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

        if (denominator == 0) {
            return false; // Segments are parallel and do not intersect
        }

        double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
        double u = ((x1 - x3) * (y1 - y2) - (y1 - y3) * (x1 - x2)) / denominator;

        return (t >= 0 && t <= 1 && u >= 0 && u <= 1); // Check if intersection point lies on both segments
    }


    void show() const {
        if (is3D) {
            cout << "3D Segment from ";
            p1_3D.show();
            cout << " to ";
            p2_3D.show();
        } else {
            cout << "2D Segment from ";
            p1.show();
            cout << " to ";
            p2.show();
        }
    }
};

int main() {
    // test for 2D points and segments
    Point p1(1, 2), p2(4, 6);
    Segment s1(p1, p2);
    cout << "Length of 2D segment: " << s1.length() << endl;

    // test for 3D points and segments
    Point3D p3D1(1, 2, 3), p3D2(4, 5, 6);
    Segment s2(p3D1, p3D2);
    cout << "Length of 3D segment: " << s2.length() << endl;

    // check intersection of two 2D segments
    Segment s3(Point(1, 1), Point(5, 5));
    Segment s4(Point(1, 5), Point(5, 1));
    cout << "Do segments intersect? " << (Segment::checkIntersection(s3, s4) ? "Yes" : "No") << endl;
}
