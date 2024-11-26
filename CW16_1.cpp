#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Person {
protected:
    string name;    // Last name
    unsigned byear; // Year of birth

public:
    virtual void input() {
        cout << "Enter last name: ";
        cin >> name;
        cout << "Enter year of birth: ";
        cin >> byear;
    }

    virtual void show() const {
        cout << "Last name: " << name << ", Year of birth: " << byear << endl;
    }

    string getName() const {
        return name;
    }

    unsigned getByear() const { // Getter for 'byear'
        return byear;
    }
};

class Friend : public Person {
private:
    string phone; // Phone number

public:
    void input() override {
        Person::input();
        cout << "Enter phone number: ";
        cin >> phone;
    }

    void show() const override {
        Person::show();
        cout << "Phone number: " << phone << endl;
    }

    void updatePhone(const string& newPhone) {
        phone = newPhone;
    }

    string getPhone() const {
        return phone;
    }
};

class PhoneBook {
private:
    vector<Friend> friends;

public:
    void addFriend() {
        if (friends.size() >= 100) {
            cout << "Phone book is full!" << endl;
            return;
        }
        Friend f;
        f.input();
        friends.push_back(f);
    }

    void searchPhoneByName(const string& searchName) const {
        for (const auto& f : friends) {
            if (f.getName() == searchName) {
                f.show();
                return;
            }
        }
        cout << "No entry found with the last name " << searchName << "." << endl;
    }

    void changePhoneByName(const string& searchName) {
        for (auto& f : friends) {
            if (f.getName() == searchName) {
                cout << "Enter new phone number for " << searchName << ": ";
                string newPhone;
                cin >> newPhone;
                f.updatePhone(newPhone);
                cout << "Phone number updated successfully." << endl;
                return;
            }
        }
        cout << "No entry found with the last name " << searchName << "." << endl;
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for writing." << endl;
            return;
        }
        for (const auto& f : friends) {
            file << f.getName() << " " << f.getByear() << " " << f.getPhone() << endl;
        }
        cout << "Data saved to file " << filename << endl;
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file for reading." << endl;
            return;
        }
        friends.clear();
        while (!file.eof()) {
            string name, phone;
            unsigned byear;
            file >> name >> byear >> phone;
            if (file.fail()) break;
            Friend f;
            f.input(); // Заповнюємо друга
            friends.push_back(f);
        }
        cout << "Data loaded from file " << filename << endl;
    }
};

int main() {
    PhoneBook book;
    int choice;

    do {
        cout << "\n1. Add a new friend\n"
             << "2. Search for a phone number by last name\n"
             << "3. Change a phone number by last name\n"
             << "4. Save the phone book to a file\n"
             << "5. Load the phone book from a file\n"
             << "6. Exit\n"
             << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            book.addFriend();
            break;
        case 2: {
            cout << "Enter last name to search: ";
            string name;
            cin >> name;
            book.searchPhoneByName(name);
            break;
        }
        case 3: {
            cout << "Enter last name to change the phone number: ";
            string name;
            cin >> name;
            book.changePhoneByName(name);
            break;
        }
        case 4:
            book.saveToFile("phonebook.txt");
            break;
        case 5:
            book.loadFromFile("phonebook.txt");
            break;
        case 6:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
