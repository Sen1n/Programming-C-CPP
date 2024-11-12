#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cctype>

using namespace std;

void reverseWord(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}

void decryptFile(const char* inputFileName, const char* outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "error opening files." << endl;
        return;
    }
    string line, word, decryptedText;
    while (getline(inputFile, line)) { 
        stringstream lineStream(line);

        while (lineStream >> word) { 
            char* cstr = &word[0];     
            reverseWord(cstr);

            decryptedText += word + " ";
        }
        decryptedText += "\n";  
    }

    outputFile << decryptedText;

    inputFile.close();
    outputFile.close();
}

int main() {
    decryptFile("encrypted.txt", "decrypted.txt");
    cout << "check 'decrypted.txt' for output." << endl;
    return 0;
}
