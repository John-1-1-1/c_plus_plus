#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class T{
public:
    long long j;
    char c;
    int i;
    short s;

    T(long long l_, char c_, int i_, short  s_){
        j = l_;
        c = c_;
        i = i_;
        s = s_;
    }

    T(){

    }

    void print() {
        cout << j << endl << c << endl << i << endl << s << endl;
    }
};

void reserializeNumber(T& d, const char* fname){
    ifstream fin(fname, ios::binary);
    fin.read((char*)&d, sizeof(T ));
    fin.close();
}

void serializeNumber(T& d, const char* fname){
    ofstream out(fname, ios::binary);
    out.write((char*)&d, sizeof(T ));
    out.close();
}



int main() {

    T t(1,97,3,4);

    serializeNumber(t, "1.txt");

    T t1;

    reserializeNumber(t1, "1.txt");

    t1.print();
}