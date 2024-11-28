#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input); 
    string word;
    vector<string> longestWords;
    int maxLength = 0;
    while (ss >> word) {
        int wordLength = word.length();
        if (wordLength > maxLength) {
            maxLength = wordLength;
            longestWords.clear(); 
            longestWords.push_back(word); 
        }
        else if (wordLength == maxLength) {
            longestWords.push_back(word);
        }
    }
    cout << "longest words: ";
    for (const string& w : longestWords) {
        cout << w << " ";
    }

    return 0;
}
