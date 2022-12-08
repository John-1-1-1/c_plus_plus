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

#pragma region iostream overloading date

ostream &operator<<(ostream &out, const Date &date) {
    out << date.year << "." << date.month << "." << date.day << endl;
    return out;
}

istream &operator>>(istream &inp, Date &date) {
    cout << "Введите год: " << endl;
    inp >> date.year;
    cout << "Введите месяц: " << endl;
    inp >> date.month;
    cout << "Введите день: " << endl;
    inp >> date.day;
    return inp;
}

#pragma endregion

class Payment {
public:
    string name;
    double salary;
    Date date;
    double perks_in_procent;
    double tax;
    double count_days_in_mount;
    double count_worker_days;
    double sum_accrued;
    double sum_withheld;

    void Init(string name, double salary, Date &date,
              double perks_in_procent, double tax, double count_days_in_mount,
              double count_worker_days, double sum_accrued, double sum_withheld) {

        this-> count_worker_days = count_worker_days;
        this->name = name;
        this->salary = salary;
        this->perks_in_procent = perks_in_procent;
        this->tax = tax;
        this->count_days_in_mount = count_days_in_mount;
        this-> count_worker_days = count_worker_days;
        this->sum_accrued = sum_accrued;
        this->sum_withheld = sum_withheld;
        this->date = date;
    }

    double get_withheld_sum(){
        sum_withheld = get_accrued_sum() / 100;
        return sum_withheld;
    }

    double  get_accrued_sum(){
        sum_accrued = salary * (count_days_in_mount - count_worker_days);
        return sum_accrued;
    }

    double  get_sum_on_hand(){
        return get_accrued_sum() - get_withheld_sum() - get_accrued_sum() *13 / 100;
    }

    int get_experience(const Date& current_date) const{
        cout<<date << endl;
        cout<< current_date << endl;
        int year = current_date.year - date.year;
        if (date.month > current_date.month){
            return year - 1;
        }
        if (date.month == current_date.month && date.day > current_date.day){
            return year - 1;
        }
        return year;
    }
};

ostream &operator<<(ostream &out, const Payment &payment) {
    out << "Name: " << payment.name << "|salary: " << payment.salary <<
        "|Date: " << payment.date << "|perks_in_procent: " <<
        payment.perks_in_procent << "|tax: " << payment.tax <<
        "|count_days_in_mount: " << "|sum_accrued: " << payment.sum_accrued <<
        "| sum_withheld: " << payment.sum_withheld;
    return out;
}

int main() {
    Date date;
    date.Init(2012, 2, 12);
    cout << date;
    date += 100;
    cout << date;
    date -= 300;
    cout << date;
    Payment payment;
    payment.Init("Cat", 12, date,12, 12, 12, 12, 23, 4);
    Date date1;
    date1.Init(2022, 1, 11);
    cout << payment.get_experience(date1) << endl;
    cout << payment;
}