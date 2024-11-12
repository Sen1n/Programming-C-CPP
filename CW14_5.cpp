#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void createStudentFile(const char* fname) {
    ofstream f1(fname);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string surname, group, marks;
        int course;
        cin >> surname >> course >> group >> marks;
        f1 << surname << " " << course << " " << group << " " << marks << "\n";
    }
    f1.close();
}

double averageMark(const string& marks) {
    double sum = 0.0;
    int counter = 0;
    stringstream str(marks);
    int tmpMark;

    while (str >> tmpMark) {
        sum += tmpMark;
        counter++;
    }

    return (counter == 0) ? 0 : (sum / counter);  
}

string findStudent(const char* fname) {
    ifstream f1(fname);
    double min_mark = 13.0;
    string loser, line;

    while (getline(f1, line)) {
        stringstream ss(line);
        string surname, group, marks;
        int course;
        
        ss >> surname >> course >> group;
        getline(ss, marks);  
        
        double avgMark = averageMark(marks);
        if (avgMark < min_mark) {
            min_mark = avgMark;
            loser = surname;
        }
    }
    return loser;
}

int main() {
    createStudentFile("students.txt");
    cout << "student with lowest average mark: " << findStudent("students.txt") << endl;
}
