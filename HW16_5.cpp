#include <iostream>
#include <string>
using namespace std;
class Word
{
protected:
    string prefix;
    string prefix2;
    string root;
    string suffix;
    string ending;

public:
    Word(string p, string p2, string r, string s, string e) : prefix(p), prefix2(p2), root(r), suffix(s), ending(e) {}

    string getPrefix() { return prefix; }
    void setPrefix(string p) { prefix = p; }

    string getPrefix2() { return prefix2; }
    void setPrefix2(string p2) { prefix2 = p2; }

    string getRoot() { return root; }
    void setRoot(string r) { root = r; }

    string getSuffix() { return suffix; }
    void setSuffix(string s) { suffix = s; }

    string getEnding() { return ending; }
    void setEnding(string e) { ending = e; }
};

class Verb : public Word
{
public:
    Verb(string p, string p2, string r, string s, string e) : Word(p, p2, r, s, e) {}
    string third()
    {
        if (root == "go")
            return "goes";
        // for other verbs
        return root;
    }
    string plural()
    {
        if (root == "goes")
            return "go";
        return root;
    }
};

class Noun : public Word
{
public:
    Noun(string p, string p2, string r, string s, string e) : Word(p, p2, r, s, e) {}
    string plural()
    {
        if (root == "house")
            return "houses";
        return root;
    }
};

class Adjective : public Word
{
public:
    Adjective(string p, string p2, string r, string s, string e) : Word(p, p2, r, s, e) {}

    string comparative()
    {
        if (root == "good")
            return "better";
        return root;
    }
};

int main()
{
    Verb v("", "", "go", "", "");
    Noun n("", "", "house", "", "");
    Adjective adj("", "", "good", "", "");

    cout << v.third() << endl;
    cout << v.plural() << endl;
    cout << n.plural() << endl;
    cout << adj.comparative() << endl;
}
