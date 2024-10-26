#include <iostream>
#include <cmath>
#include<fstream>
using namespace std;

void task1(){
    double x, y, res;
    cin >> x;
    cin >> y;
    res = pow(x, y);
    cout <<  res << ", " <<scientific << res << endl;

}

void task2(){
    size_t sz;
    char str[10];
    unsigned a;
    unsigned long long sum = 0UL; // UL - нагадування, що це анасайнед лонг
    unsigned n = 0;
    cout << "Enter n:\n";
    // atoi (char* перерводить в ціле число)
    unsigned mas[1000];
    while(cin.get(str, 11)){
        cout << str << ", " << endl;
        // a = atoi(str) // падає, якщо не число, кастить чар до інта
        a = stoul(str, &sz); // в другий параметр &sz -1 якщо окей, або номер символу, де лажа, індексація з 0 - це str; sto l u i
        mas[n] = a;
        n++;
        sum += a;
    }
    cout << "s" << sum << "\n";
}

void task3(){
    unsigned n;
    double res;
    cout<<"Enter n: ";
    cin >> n;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    for(int i=1; i<=n; i++){
        cout<<" "<<i<<"      ";
    }
    cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    for(int i=1; i<=n; i++){
        res = sqrt(i);
        cout.precision(3);
        cout<<" "<<res<<"    ";
    }
}

void task4(){
    unsigned n;
    cin>>n;
    int *m = new int[n];
    double *x = new double[n];
    for(unsigned i=0; i<n; i++){
        cout<<"m["<<i<<"] = ";
        cin>>m[i];
    }
    ifstream f1("input4.txt");
    unsigned i=0;
    while(!f1.eof()){
        if(f1>>x[i]){
            clog<<i<<"-th number = x["<<i+1<<"] "<<"\n"; //поправити
            i++;
        }
        if(i>=n){
            break;
        }
    }
    f1.close();
    if(i<n){
        cout<<"\nnot enough data in file";
    }
    ofstream f2("output4.txt");
    for(unsigned i=0; i<n; i++){
        double z=pow(x[i], m[i]);
        f2<<z<<"\n";
    }
    f2.close();
    delete[]x;
    delete[]m;

}


void task5() {
    ifstream inputFile("input5.txt"); 
    if (!inputFile) {
        cerr << "error opening input file." << endl;
        return;
    }

    unsigned long long numbers[1000]; 
    int count = 0;
    unsigned long long num;

    while (inputFile >> num && count < 1000) {
        numbers[count++] = num;
    }
    inputFile.close();
    ofstream outputFile("output5.txt");
    if (!outputFile) {
        cerr << "error opening output file." << endl;
        return;
    }

    
    outputFile << fixed; 
    for (int i = count - 1; i >= 0; --i) {
 
        if (numbers[i] >= 0) {
            double sqrtResult = sqrt(numbers[i]);
            outputFile.precision(3); 
            outputFile << sqrtResult << endl;
        } else {
            outputFile << "invalid input cause negative number" << endl;
        }
    }

    outputFile.close();
}


int main(){
    // task1();
    // task2();
    // task3();
    // task4();
    task5();
}