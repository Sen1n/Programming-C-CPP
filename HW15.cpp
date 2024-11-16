#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cmath>

class Vector {
private:
    int size;      
    double* data;  

public:
    Vector(int n) : size(n), data(new double[n]) {
        if (n <= 0) {
            throw std::invalid_argument("Vector size must be greater than 0");
        }
    }

    //copy constructor
    Vector(const Vector& other) : size(other.size), data(new double[other.size]) {
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    //destructor
    ~Vector() {
        delete[] data;
    }

    void fillVector(double* values) {
        for (int i = 0; i < size; ++i) {
            data[i] = values[i];
        }
    }

    void fillVector() {
        for (int i = 0; i < size; ++i) {
            std::cout << "Enter element #" << i + 1 << ": ";
            std::cin >> data[i];
        }
    }

    double& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    void printVector() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    double scalarProduct(const Vector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Vector sizes do not match");
        }
        double result = 0.0;
        for (int i = 0; i < size; ++i) {
            result += data[i] * other.data[i];
        }
        return result;
    }

    Vector vectorProduct(const Vector& other) const {
        if (size != 3 || other.size != 3) {
            throw std::invalid_argument("Vector product is possible only for 3D vectors");
        }
        Vector result(3);
        result[0] = data[1] * other.data[2] - data[2] * other.data[1];
        result[1] = data[2] * other.data[0] - data[0] * other.data[2];
        result[2] = data[0] * other.data[1] - data[1] * other.data[0];
        return result;
    }

    void readFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::ios_base::failure("Failed to open file");
        }

        for (int i = 0; i < size; ++i) {
            file >> data[i];
        }
        file.close();
    }

    void writeToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::ios_base::failure("Failed to open file");
        }

        for (int i = 0; i < size; ++i) {
            file << data[i] << " ";
        }
        file.close();
    }
};

int main() {
    try {

        Vector vec1(3);
        vec1.fillVector();
        std::cout << "Vector 1: ";
        vec1.printVector();


        Vector vec2(3);
        vec2.fillVector();
        std::cout << "Vector 2: ";
        vec2.printVector();

        //scalar product
        std::cout << "Scalar product: " << vec1.scalarProduct(vec2) << std::endl;

        //vector product
        Vector vec3 = vec1.vectorProduct(vec2);
        std::cout << "Vector product: ";
        vec3.printVector();

        //write the vector to a file
        vec1.writeToFile("vector1.txt");

        //read the vector from a file
        Vector vec4(3);
        vec4.readFromFile("vector1.txt");
        std::cout << "Read vector from file: ";
        vec4.printVector();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }


}
