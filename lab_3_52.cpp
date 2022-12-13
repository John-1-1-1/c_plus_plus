#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class Array{
protected:
    static const int size_variable = 1000;
    unsigned char args[size_variable];
    int size;

public:
    Array(){
        memset(&args,NULL,1000);
        size = 0;
    }

    Array(unsigned char array[], int size){
        memset(&args,NULL,1000);
        for (int i =  0; i < size; i++){
            args[i] = array[i];
        }
        this->size = size;
    }

    int getSize() const {
        return size;
    }

    unsigned char &operator[] (const int index)
    {
        if (index < 0 || index >= size) {
            throw "Выход за диапазон массива";
        }
        return args[index];
    }

    unsigned char operator[] (const int index) const
    {
        if (index < 0 || index >= size_variable) {
            throw "Выход за диапазон массива";
        }
        return args[index];
    }

    void add(unsigned char c){
        size += 1;
        args[size - 1] = c;
    }

    virtual Array sum(Array& array){
        Array arr;
        for (int i = 0; i < size; i ++) {
            arr.add(args[i] + array[i]);
        }
        return arr;
    }

};

class Decimal: public Array{
public:
    Decimal(): Array(){}

    Decimal(unsigned char array[], int size): Array(array, size){}

    Decimal sum(Decimal& decimal){
        Decimal arr;
        for (int i = 0; i < size; i ++) {
            arr.add(args[i] + decimal[i]);
        }
        return arr;
    }

};

class Hex: public Array{
public:
    Hex(): Array(){}

    Hex(unsigned char array[], int size): Array(array, size){}

    Hex sum(Hex& hex){
        Hex arr;
        for (int i = 0; i < size; i ++) {
            arr.add(args[i] + hex[i]);
        }
        return arr;
    }

};

ostream& operator<< (ostream& out, const Array& array) {
    for (int i = 0; i < array.getSize(); i++) {
        cout << array[i];
    }
    cout << endl;
    return out;
}

ostream& operator<< (ostream& out, const Decimal& decimal) {
    for (int i = 0; i < decimal.getSize(); i++) {
        cout << int(decimal[i]) << " ";
    }
    cout << endl;
    return out;
}

ostream& operator<< (ostream& out, const Hex& hex) {
    for (int i = 0; i < hex.getSize(); i++) {
        cout << std::hex << int(hex[i]) << " ";
    }
    cout << endl;
    return out;
}


int main() {
    unsigned char a[] = {'a','b','c','d'};
    Array ar(a, 4);
    unsigned char a1[] = {9,1,1,1};
    Array ar1(a1, 4);
    Array c =  ar.sum(ar1);


    cout <<c;

    Decimal de(a, 4);
    Decimal de1(a1, 4);
    Decimal cde =  de.sum(de1);

    cout <<cde;

    Hex hex(a, 4);
    Hex hex1(a1, 4);
    Hex chex =  hex.sum(hex1);

    cout <<chex;
}