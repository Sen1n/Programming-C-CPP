#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> partialSplit(const string& input, char delimiter, int n) {
    vector<string> result;
    stringstream ss(input);
    string token;

    while (getline(ss, token, delimiter)) {
        result.push_back(token);
        if (result.size() == n) {
            break;
        }
    }

    return result;
}

int main() {
    string input;
    char delimiter;
    int n;

    cout << "enter the string: ";
    getline(cin, input);

    cout << "enteer delimiter: ";
    cin >> delimiter;

    cout << "enter numbers: ";
    cin >> n;

    vector<string> words = partialSplit(input, delimiter, n);

    cout << "res words: ";
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;

}
