#include <iostream>
#include <cmath>

using namespace std;

class List {
private:
    int size;
public:
    int* args;
    List(int size) {
        args = (int*)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++) {
            args[i] = rand() % 100 - 50;
        }
        this->size = size;
    }

    List(const int* array, int size) {
        args = (int*)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++) {
            args[i] = array[i];
        }
        this->size = size;
    }

    void add_number(int num) {
        args = (int*)realloc(args, sizeof(int) * (size + 1));
        args[size] = num;
        size += 1;
    }

    int sum() const {
        int s = 0;
        for (int i = 0; i < size; i++) {
            s += args[i];
        }
        return s;
    }

    int srednee() const {
        return sum() / size;
    }

    int sredneeABS() const {
        int s = 0;
        for (int i = 0; i < size; i++) {
            s += abs(args[i]);
        }
        return s / size;
    }

    int getSize() const {
        return size;
    }

    int max() {
        int max = args[0];
        for (int i = 0; i < size; i++) {
            if (max < args[i]) {
                max = args[i];
            }
        }
        return max;
    }

    int min() {
        int min = args[0];
        for (int i = 0; i < size; i++) {
            if (min > args[i]) {
                min = args[i];
            }
        }
        return min;
    }

    int operator[] (const int index) const
    {
        if (index < 0 || index >= size) {
            throw "Выход за диапазон массива";
        }
        return args[index];
    }

    List& operator+ (const int index) {
        for (int i = 0; i < size; i++) {
            args[i] = args[i] + index;
        }
        return  *this;
    }

    List& operator- (const int index) {
        return operator+(-index);
    }

    List& operator* (const int index) {
        for (int i = 0; i < size; i++) {
            args[i] = args[i] * index;
        }
        return  *this;
    }
};

ostream& operator<< (ostream& out, const List list) {

    for (int i = 0; i < list.getSize(); i++) {
        cout << list.args[i] << " ";
    }

    cout << endl;
    return out;
}

int main() {
    srand(0);

    List list(10);
    cout << list;
    list.add_number(1);
    cout << list;


    //1
    list = list + list.max() * list[list.getSize() - 1];
    cout << list;
    //3
    list = list -list.max();
    cout << list;
    //4
    list = list * list.min();
    cout << list;
    //6
    list = list - list.sum();
    cout << list;
    return 0;
}