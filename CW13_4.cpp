#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<double> extractNumbers(const string& input, char delimiter, int n) {
    vector<double> result;
    stringstream ss(input);
    string token;
    while (getline(ss, token, delimiter)) {
        try {
            double num = stod(token);
            result.push_back(num);

            if (result.size() == n) {
                break;
            }
        } catch (const invalid_argument& e) {
            continue;
        }
    }

    return result;
}

int main() {
    string input;
    char delimiter;
    int n;

    cout << "enter string: ";
    getline(cin, input);
    cout << "enter delimiter: ";
    cin >> delimiter;
    cout << "enter number: ";
    cin >> n;
    vector<double> numbers = extractNumbers(input, delimiter, n);
    cout << "numbers: ";
    for (double num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
