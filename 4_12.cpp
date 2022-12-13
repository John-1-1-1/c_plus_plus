#include <iostream>
#include <cmath>
#include <cstring>
#include <exception>

using namespace std;

class Date{
private:
    const int days[13] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day,mount,year;

    int visocosniGod(int year){
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return true;
            }
        }
        else {
            return false;
        }

    }

public:
    Date(int day, int mount, int year){
        this->day = day;
        this->mount = mount;
        this->year = year;
    }

    Date() {}

    int getDay(){
        return day;
    }

    int getMount(){
        return mount;
    }

    int getDaysInMount(int m){
        return days[m];
    }

    int getDaysInYear(int year){
        if (visocosniGod(year)){
            return 366;
        }
        else{
            return 365;
        }
    }

    int getYear(){
        return year;
    }
};

int DaysRaznost(Date& d1, Date& d2){
    int s = 0;
    int y1 = d1.getYear();
    int y2 = d2.getYear();

    while (y1 < y2){
        s += d1.getDaysInYear(y1);
        y1+=1;
    }
    s -= d1.getDay();
    s += d2.getDay();

    int m1 = 0;

    while (m1 < d1.getMount()){
        s -= d1.getDaysInMount(m1);
        m1+=1;
    }

    int m2 = 0;

    while (m2 < d2.getMount()){
        s += d2.getDaysInMount(m2);
        m2+=1;
    }

    return s;

}


int DaysRaznostThrow(Date& d1, Date& d2){

    if (d1.getMount() > d2.getMount() ||
        d1.getDay() > d2.getDay() ||
        d1.getYear() > d2.getYear()){
        throw;
    }

    int s = 0;
    int y1 = d1.getYear();
    int y2 = d2.getYear();

    while (y1 < y2){
        s += d1.getDaysInYear(y1);
        y1+=1;
    }
    s -= d1.getDay();
    s += d2.getDay();

    int m1 = 0;

    while (m1 < d1.getMount()){
        s -= d1.getDaysInMount(m1);
        m1+=1;
    }

    int m2 = 0;

    while (m2 < d2.getMount()){
        s += d2.getDaysInMount(m2);
        m2+=1;
    }

    return s;

}


int DaysRaznostThrow_RangeError(Date& d1, Date& d2){

    if (d1.getMount() > d2.getMount() ||
        d1.getDay() > d2.getDay() ||
        d1.getYear() > d2.getYear()){
        throw range_error("Error! date1 > date 2");
    }

    int s = 0;
    int y1 = d1.getYear();
    int y2 = d2.getYear();

    while (y1 < y2){
        s += d1.getDaysInYear(y1);
        y1+=1;
    }
    s -= d1.getDay();
    s += d2.getDay();

    int m1 = 0;

    while (m1 < d1.getMount()){
        s -= d1.getDaysInMount(m1);
        m1+=1;
    }

    int m2 = 0;

    while (m2 < d2.getMount()){
        s += d2.getDaysInMount(m2);
        m2+=1;
    }

    return s;

}

class rangeError:public exception {
    const char* what() const noexcept
    {return " date1 > date 2!! ";
        }
};

int DaysRaznostThrow_MyException(Date& d1, Date& d2){

    if (d1.getMount() > d2.getMount() ||
        d1.getDay() > d2.getDay() ||
        d1.getYear() > d2.getYear()){
        throw rangeError();
    }

    int s = 0;
    int y1 = d1.getYear();
    int y2 = d2.getYear();

    while (y1 < y2){
        s += d1.getDaysInYear(y1);
        y1+=1;
    }
    s -= d1.getDay();
    s += d2.getDay();

    int m1 = 0;

    while (m1 < d1.getMount()){
        s -= d1.getDaysInMount(m1);
        m1+=1;
    }

    int m2 = 0;

    while (m2 < d2.getMount()){
        s += d2.getDaysInMount(m2);
        m2+=1;
    }

    return s;

}




int main() {
    Date d1(1,2,3);
    Date d2(2,3,4);

    cout << DaysRaznost( d1, d2);
    cout << DaysRaznostThrow_MyException( d2, d1);
}