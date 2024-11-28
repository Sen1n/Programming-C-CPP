#include <iostream>
#include <string>

using namespace std;

int main() {
    string input = "Maksym's cat is big";
    string result;
    size_t pos = 0;
    while ((pos = input.find("'s ")) != string::npos) {
        size_t name_start = input.rfind(' ', pos - 1);
        string name = input.substr(name_start + 1, pos - name_start - 1);
        size_t item_start = pos + 3;
        size_t item_end = input.find(' ', item_start);
        if (item_end == string::npos) item_end = input.length();
        string item = input.substr(item_start, item_end - item_start);
        result += item + " of " + name + input.substr(item_end);
        input = result;
        result.clear();
    }
    cout << input << endl;
}
