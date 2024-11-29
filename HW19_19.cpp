#include <iostream>
#include <deque>
#include <fstream>
using namespace std;

int main() {
    deque<int> d; 
    ifstream inputFile("input.txt");  

    if (!inputFile) {
        cerr << "failed to open the file!" << endl;
        return 1;
    }

    int value;
    while (inputFile >> value) {
        d.push_back(value);
    }
    inputFile.close(); 
    int size = d.size();

    if (size % 2 == 1) {
        int middleIndex = size / 2;
        auto it = d.begin() + middleIndex;
        d.erase(it);
    } else {
        int middleIndex1 = size / 2 - 1;
        int middleIndex2 = size / 2;
        auto it1 = d.begin() + middleIndex1;
        auto it2 = d.begin() + middleIndex2;
        d.erase(it1);
        d.erase(it2);
    }
    cout << "result after removing the middle elements:" << endl;
    for (int elem : d) {
        cout << elem << " ";
    }
}
