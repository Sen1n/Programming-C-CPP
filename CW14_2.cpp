#include<iostream>
#include<cctype>
#include<fstream>

int main() {

    char fname[20] = "input.txt";
    std::ifstream input(fname);
    std::string Articles[] = { "der", "die", "das" };
    std::string buf;
    bool isArticle = false;
    std::ofstream input2("tmp.txt");
    while (input >> buf) {
        if (isArticle) {
            buf[0] = toupper(buf[0]);
        }
        std::clog << buf << " ";
        input2 << buf << " ";
        isArticle = false;
        for (int i = 0; i < 3; i++) {
            if (buf == Articles[i]) {
                isArticle = true;
                break;
            }
        }
    }
    input.close();
    input2.close();
    rename("tmp.txt", fname);
}
