#include <iostream>
#include <cmath>
using namespace std;


class Triada{

private:
    int a;
    int b;
    int c;

public:
    Triada(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c =c;
    }

    int get_A(){
        return a;
    }

    int get_B(){
        return b;
    }

    int get_C(){
        return c;
    }

    bool operator==(Triada triada){
        return this->get_A() == triada.get_A() &&
                this->get_B() == triada.get_B() &&
                this->get_C() == triada.get_C();
    }

    bool operator!=(Triada triada){
        return this->get_A() != triada.get_A() ||
               this->get_B() != triada.get_B() ||
               this->get_C() != triada.get_C();
    }

    bool operator>(Triada triada){

        if (this->get_C() > triada.get_C()){
            return true;
        }else if (this->get_C() == triada.get_C()){
            if (this->get_B() > triada.get_B())
            {
                return true;
            } else if (this->get_B() == triada.get_B()){
               return this->get_A() > triada.get_A();
            }
        }
    }

    bool operator<(Triada triada){

        if (this->get_C() < triada.get_C()){
            return true;
        }else if (this->get_C() == triada.get_C()){
            if (this->get_B() < triada.get_B())
            {
                return true;
            } else if (this->get_B() == triada.get_B()){
                return this->get_A() < triada.get_A();
            }
        }
    }
};

class Date: Triada{

public:
    Date(int day, int mount, int year) : Triada(day, mount, year) {

    }

    int getDay(){
        return get_A();
    }

    int getMount(){
        return get_B();
    }

    int getYear(){
        return get_C();
    }

    bool operator==(Date date){
        return (Triada)*this == (Triada)date;
    }

    bool operator!=(Date date){
        return (Triada)*this != (Triada)date;
    }

    bool operator>(Date date){
        return (Triada)*this > (Triada)date;
    }

    bool operator<(Date date){
        return (Triada)*this < (Triada)date;
    }
};

int main()
{
    auto d1 = Date(1, 2, 3);
    auto d2 = Date(2,2,3);

    cout << (d1 == d2);
    cout << (d1 < d2);

    return 0;
}