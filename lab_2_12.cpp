#include <iostream>
#include <cmath>


using namespace std;

class Date {
private:
    const int days[13] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
    unsigned int year;
    unsigned int month;
    int day;

    void Init(const unsigned int year,
              const unsigned int month,
              const unsigned int day) {
        this->year = year;
        this->day = day;
        this->month = month;
    }

    string toString() {

        return to_string(year) + "." + to_string(month) + "." + to_string(day);
    }

    bool IsLeapYear(int year) {
        if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
            return true;
        }
        return false;
    }

    bool IsThisLeapYear() {
        return IsLeapYear(year);
    }

    void operator+=(const int &rhs) {
        this->day += rhs;
        Normalize();
    }

    void operator-=(const int &rhs) {
        this->day -= rhs;
        Normalize();
    }

    unsigned int Day() {
        return day;
    }

    unsigned int Mount() {
        return month;
    }

    unsigned int Year() {
        return year;
    }


    Date &operator=(Date &date) {
        this->year = date.year;
        this->day = date.day;
        this->month = date.month;
        return *this;
    }

private:
    void Normalize() {
        while (day > YearsOfMonth(year, month) || day <= 0) {
            if (day <= 0) {
                day += YearsOfMonth(year, month - 1);
                if (month == 1) {
                    month = 12;
                    year--;
                } else {
                    month--;
                }
            } else {
                day -= YearsOfMonth(year, month);
                if (month == 12) {
                    year++;
                    month = 1;
                } else {
                    month++;
                }
            }
        }
    }

    int YearsOfMonth(const unsigned int y, unsigned int m) {
        int dayInMonth;
        dayInMonth = days[m];
        if (month == 2 && IsLeapYear(y)) {
            dayInMonth += 1;
        }
        return dayInMonth;
    }
};



class Person{
private:
    string Name;
    Date date;
public:
    Person(Date& date, string Name, string LastName){
        this->date = date;
        this->LastName = LastName;
        this->Name = Name;
    }

    string LastName;


};

class ListPerson{
public:

    static const int size = 1000;

    Person* listPerson[size] = {nullptr};

    ListPerson() {

    }

    bool Add(Person &person){
        int i;
        for (i = 0; i < size; i++)
        {
            if (listPerson[i] == nullptr) {
                break;
            }
            if (listPerson[i]->LastName == person.LastName){
                return false;
            }
        }
        listPerson[i] = &person;
        return true;
    }

    void Del(const int index){
        listPerson[index] = nullptr;
    }

    Person* GetPersonByLastName(const string& LastName){
        for (int i = 0; i < size; i ++){
            if (listPerson[i] == nullptr){
                return nullptr;
            }
            if (listPerson[i]->LastName == LastName){
                return listPerson[i];
            }
        }
        return nullptr;
    }

    Person& operator[](const int index){
        return *(this->listPerson[index]);
    }

    ListPerson Union(ListPerson& listPerson){

        for (int i = 0; i < listPerson.size; i ++){
            if (&listPerson[i] != 0) {
                this->Add(listPerson[i]);
            }

        }
        return *this;
    }

    ListPerson Confluence(ListPerson& listPers){
        ListPerson lp;
        int index_i;
        int index_j;

        for (index_i = 0; index_i < ListPerson::size; index_i++){
            if (&(listPers[index_i]) == nullptr){
                continue;
            }
            for(index_j = index_i+1; index_j < ListPerson::size; index_j ++){
                if (&(this->listPerson[index_j]) == nullptr){
                    continue;
                }


                if (this->listPerson[index_j]->LastName == listPers[index_i].LastName){
                    lp.Add(*this->listPerson[index_j]);
                }
            }
        }

        return lp;
    }

    void print(){
        for (int i = 0; i < size; i++){
            if (listPerson[i] != nullptr) {
                cout << listPerson[i]->LastName << endl;
            }
        }
    }
};

int main(){

    ListPerson lp;
    Date d;
    d.Init(2002,2,2);
    Person p(d, "", "Cat");

    Person p1(d, "", "Dog");
    lp.Add(p);

    lp.Add(p1);
    lp.Add(p);

    auto t = lp.GetPersonByLastName("Dog");

    cout<< t->LastName << endl;
    cout << "---" << endl;
    lp.print();


    Person p2(d, "", "Cat");
    Person p3(d, "", "Do0g");


    ListPerson lp1;
    lp1.Add(p2);
    lp1.Add(p3);

    cout << "---"<<endl;


    lp1.print();

    ListPerson lp2 =  lp.Union(lp1);


    cout << "---"<<endl;
    lp2.print();

    cout << "---"<<endl;
    ListPerson lp3  = lp.Union(lp1);
    lp3.print();


    return 0;
}