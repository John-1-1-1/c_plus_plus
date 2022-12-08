#include <iostream>
#include <cmath>
#include <utility>
#include "T.h"

using namespace std;

class Person {
public:
    string name;

    Person(string _name): name(std::move(_name)){

    }
};

class Company{
public:

    string  name;
    Person ** pers;

    Company(string _name):name(_name) {

    }
};


int main(){
   /*
    Person per1("Cat"), per2("Anton"), per3("ARINA"),
            per4("Din");

    Company com1("caaat");

    Person* pers[3] = {&per1, &per2, &per3};

    com1.pers = pers;
*/

   T t(3);
   t.print();
}