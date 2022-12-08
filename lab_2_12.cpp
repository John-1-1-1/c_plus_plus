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

    Date(){

    }

    Date(const unsigned int year,
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

class Zodiac{

public:
    Zodiac() {

    }

    Date DateBegin;
    Date DateEnd;
    string Name;

    Zodiac(Date& dateBegin,Date& dateEnd,string name) {
        DateBegin = dateBegin;
        DateEnd = dateEnd;
        Name = name;
    }
};

class Person{
private:
    string Name;
    Date *date;
public:
    Person(Date& date, string Name, string LastName){
        this->date = &date;
        this->LastName = LastName;
        this->Name = Name;
    }

    string LastName;

    Date getDate(){
        return *this->date;
    }
};

class ListPerson{
private:

public:

    static const int size = 1000;
    static const int size_z = 12;
    static Zodiac zodiac[size_z];


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
        ListPerson lp;
        for (int i = 0; i < listPerson.size; i ++){
            if (&listPerson[i] != 0) {
                lp.Add(listPerson[i]);
            }

        }
        return lp;
    }

    ListPerson Confluence(ListPerson& listPers){
        ListPerson lp;
        int index_i;
        int index_j;

        for (index_i = 0; index_i < ListPerson::size; index_i++){
            if (listPers.listPerson[index_i] == nullptr){
                continue;
            }
            for(index_j = 0; index_j < ListPerson::size; index_j ++){
                if (this->listPerson[index_j] == nullptr){
                    continue;
                }

                if (this->listPerson[index_j]->LastName == listPers[index_i].LastName){
                    lp.Add(*this->listPerson[index_j]);
                }
            }
        }
        return lp;
    }

    ListPerson Residual(ListPerson& listPers){
        ListPerson lp;

        int index_i;
        int index_j;

        for (index_i = 0; index_i < ListPerson::size; index_i++){
            if (listPers.listPerson[index_i] == nullptr){
                continue;
            }

            bool added = true;

            for(index_j = 0; index_j < ListPerson::size; index_j ++){
                if (this->listPerson[index_j] == nullptr){
                    continue;
                }

                if (this->listPerson[index_j]->LastName == listPers[index_i].LastName){
                    added = false;
                }
            }

            if (added){
                lp.Add(*this->listPerson[index_i]);
            }
        }

        for (index_i = 0; index_i < ListPerson::size; index_i++){
            if (this->listPerson[index_i] == nullptr){
                continue;
            }

            bool added = true;

            for(index_j = 0; index_j < ListPerson::size; index_j ++){
                if (listPers.listPerson[index_j] == nullptr){
                    continue;
                }

                if (listPers.listPerson[index_j]->LastName == this->listPerson[index_i]->LastName){
                    added = false;
                }
            }

            if (added){
                lp.Add(listPers[index_i]);
            }
        }

        return lp;
    }

    string get_Zodiac(string LastName){
        for (int index = 0; index < ListPerson::size; index ++)
        {
            if (listPerson[index] != nullptr){
                if (listPerson[index]->LastName == LastName){
                    auto date = listPerson[index]->getDate();
                    for (int index_z = 0; index_z < ListPerson::size_z; index_z ++){
                        if (date.month == zodiac[index_z].DateEnd.month &&
                        date.day <= zodiac[index_z].DateEnd.day
                        || date.month == zodiac[index_z].DateBegin.month &&
                        date.day >= zodiac[index_z].DateBegin.day){
                            return zodiac[index_z].Name;
                        }
                    }

                }
            }
        }
    }

    void print(){
        for (auto & i : listPerson){
            if (i != nullptr) {
                cout << i->LastName << endl;
            }
        }
    }
};

Zodiac ListPerson::zodiac[12] {
        Zodiac(*new Date(0, 3,21) ,*new Date(0, 4,20), "Овен"),
        Zodiac(*new Date(0, 4,21) ,*new Date(0, 5,21), "Телец"),
        Zodiac(*new Date(0, 5,22) ,*new Date(0, 6,21), "Близнецы"),
        Zodiac(*new Date(0, 6,22) ,*new Date(0, 7,22), "Рак"),
        Zodiac(*new Date(0, 7,22) ,*new Date(0, 8,23), "Лев"),
        Zodiac(*new Date(0, 8,24) ,*new Date(0, 9,22), "Дева"),
        Zodiac(*new Date(0, 9,23) ,*new Date(0, 10,23), "Весы"),
        Zodiac(*new Date(0, 10,24) ,*new Date(0, 11,22), "Скорпион"),
        Zodiac(*new Date(0, 11,23) ,*new Date(0, 12,21), "Стрелец"),
        Zodiac(*new Date(0, 12,22) ,*new Date(0, 1,20), "Козерог"),
        Zodiac(*new Date(0, 1,21) ,*new Date(0, 2,18), "Водолей"),
        Zodiac(*new Date(0, 2,19) ,*new Date(0, 3,20), "Рыбы"),

};


int main(){

    ListPerson lp;
    Date d(2002,2,2);
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
    ListPerson lp3  = lp.Confluence(lp1);
    lp3.print();

    cout << "---"<<endl;
    lp3  = lp.Residual(lp1);
    lp3.print();

    cout << "---" << endl;
    cout << lp.get_Zodiac("Cat");

    return 0;
}