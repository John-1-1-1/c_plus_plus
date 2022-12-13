#include <iostream>
#include <cmath>

using namespace std;

template< typename T>

class List{
private:
    T* args;
    int size;

public:
    List(){
        size = 0;
    }

    void add(T obj){
        args = (int*)realloc(args, sizeof(int) * (size + 1));
        args[size] = obj;
        size += 1;
    }

    T operator[](const int index) const{
        return args[index];
    }

    T& operator[](int index) {
        return args[index];
    }

};

int main() {
    List<int> l;
    l.add(1);
    l[0] = 100;
    cout << l[0];
}