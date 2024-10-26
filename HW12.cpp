//12.8

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;


struct Point {
    int x, y;
};


struct Segment {
    Point p1, p2;
    double length;

    Segment(Point a, Point b) : p1(a), p2(b) {
        length = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    }
};


vector<Point> readPoints(const string &filename) {
    fstream f(filename);
    if (!f) {
        cerr << "error reading file: " << filename << "\n";
        exit(1);
    }

    vector<Point> points;
    string line;
    while (getline(f, line)) {
        stringstream ss(line);
        char ch;
        int x, y;
        while (ss >> ch) {
            if (ch == '(' && ss >> x >> ch && ch == ',' && ss >> y >> ch && ch == ')') {
                points.push_back({x, y});
            }
        }
    }

    return points;
}


vector<Segment> createSegments(const vector<Point> &points) {
    vector<Segment> segments;
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            segments.push_back(Segment(points[i], points[j]));
        }
    }
    return segments;
}


void writeSegments(const vector<Segment> &segments, const string &filename) {
    fstream f(filename, ios::out);
    if (!f) {
        cerr << "error writing to file: " << filename << "\n";
        exit(1);
    }

    for (const auto &seg : segments) {
        f << "(" << seg.p1.x << ", " << seg.p1.y << ") to ("
          << seg.p2.x << ", " << seg.p2.y << ") - length: " << seg.length << "\n";
    }
}

int main() {
    string inputFile = "points.txt";
    string outputFile = "segments.txt";

    vector<Point> points = readPoints(inputFile);

    cout << "points read from file:\n";
    for (const auto &p : points) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    if (points.empty()) {
        cerr << "no points were read from the file. Please check the file format.\n";
        return -1;
    }

    vector<Segment> segments = createSegments(points);

    sort(segments.begin(), segments.end(), [](const Segment &a, const Segment &b) {
        return a.length < b.length;
    });

    writeSegments(segments, outputFile);

    cout << "segments sorted and written to " << outputFile << "\n";
    return 0;
}
