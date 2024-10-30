#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int line1, line2;
    cout << "enter the first line number: ";
    cin >> line1;
    cout << "enter the second line number: ";
    cin >> line2;

    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "failed to open the input file" << endl;
        return 1;
    }

    vector<string> lines; /* чесно кажучи, я не знав як краще зберігати рядки, 
    програма зчитує рядки з файлу один за одним і зберігає їх у векторі lines.*/
    string line;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();


    if (line1 <= 0 || line2 <= 0 || line1 >= line2 || line2 > lines.size()) {
        ofstream outputFile("output.txt");
        outputFile << "remove is imposiible" << endl;
        outputFile.close();
        cerr << "remove is imposiible" << endl;
        return 1;
    }


    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "failed to open the output file." << endl;
        return 1;
    }


    for (size_t i = 0; i < lines.size(); ++i) {
        if (i + 1 < line1 || i + 1 > line2) {
            outputFile << lines[i] << endl;
        }
    }

    outputFile.close();
    cout << "lines successfully written to output.txt" << endl;
    return 0;
}
