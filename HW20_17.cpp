#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
    vector<string> V = {"apple", "banana", "orange", "apricot", "grape", "kiwi", "a"};
    multimap<char, string> M;
    for (const auto& word : V) {
        // якщо слово складається з 1 літери, використовуємо першу літеру як ключ
        if (word.length() == 1) {
            M.insert({word[0], word});
        } else {
            M.insert({word[1], word}); //друга літера використовується як ключ
        }
    }
    for (const auto& entry : M) {
        cout << "key: " << entry.first << " ---- value: " << entry.second << endl;
    }
}
