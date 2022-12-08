#include <iostream>
#include <cmath>

using namespace std;

int f1(int x){
    return x + 1;
}

long f2(int x){
    return x + 2;
}

int main(){

    long (*f)(int);
    f=f2;


    return 0;
}