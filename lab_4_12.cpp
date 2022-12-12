#include <iostream>
#include <cmath>


using namespace std;

class A{
public:
    int i = 1;
};

class B: private A{

};

int main(){

    A* b = new A();

    return 0;
}