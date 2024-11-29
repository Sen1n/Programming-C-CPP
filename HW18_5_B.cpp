#include <iostream>
#include <vector>
#include <algorithm> // for swap
using namespace std;

template <typename T>
class Array {
private:
    vector<T> data; 

public:

    Array() = default;
    Array(initializer_list<T> lst) : data(lst) {}
    void add(const T& value) {
        data.push_back(value);
    }
    size_t size() const {
        return data.size();
    }
    void print() const {
        for (const auto& element : data) {
            cout << element << " ";
        }
        cout << endl;
    }
    void selectionSortInPlace() {
        size_t n = data.size();
        for (size_t i = 0; i < n - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < n; ++j) {
                if (data[j] < data[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(data[i], data[minIndex]);
            }
        }
    }
    static void selectionSortArrayInPlace(vector<T>& array) {
        size_t n = array.size();
        for (size_t i = 0; i < n - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < n; ++j) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(array[i], array[minIndex]);
            }
        }
    }
};

int main() {
    Array<int> myArray = {5, 3, 8, 6, 2};
    cout << "initial array: ";
    myArray.print();
    myArray.selectionSortInPlace();
    cout << "sorted array: ";
    myArray.print();
    vector<int> anotherArray = {7, 4, 9, 1, 3};
    cout << "another array before sorting: ";
    for (const auto& element : anotherArray) {
        cout << element << " ";
    }
    cout << endl;
    Array<int>::selectionSortArrayInPlace(anotherArray);
    cout << "another array after sorting: ";
    for (const auto& element : anotherArray) {
        cout << element << " ";
    }
    cout << endl;

}
