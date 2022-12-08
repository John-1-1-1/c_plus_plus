#include <iostream>
#include <cmath>
using namespace std;

struct AccountData
{
    string last_name;
    string UID;
    float percent;
    float sum;
};

void Init(AccountData &Acc, string _last_name,
          string _UID, float _percent, float _sum)
{
    Acc.last_name = _last_name;
    Acc.UID = _UID;
    Acc.percent = _percent;
    Acc.sum = _sum;
}

bool ChangeMaster(AccountData &Acc, string _last_name)
{
    if (_last_name == "")
    {
        return false;
    }

    Acc.last_name = _last_name;
    return true;
}

bool GetSum(AccountData &Acc, float _sum)
{
    if (_sum <= 0 || _sum > Acc.sum)
    {
        return false;
    }

    Acc.sum -= _sum;
    return true;
}

bool AddSum(AccountData &Acc, float _sum)
{
    if (_sum <= 0){
        return false;
    }
    Acc.sum += _sum;
    return true;
}

void PlusPetcent(AccountData &Acc)
{
    Acc.sum += Acc.sum * Acc.percent;
}

float ShowInEuro(const AccountData &Acc, float Euro)
{
    return Acc.sum / Euro;
}

float ShowInDollar(const AccountData &Acc, float Dollar)
{
    return Acc.sum / Dollar;
}

int ShowSumInNumeral(const AccountData &Acc)
{
    return Acc.sum;
}

void Read(AccountData &Acc)
{
    cout << "Input last_name: ";
    cin >> Acc.last_name;
    cout << "Input UID: ";
    cin >> Acc.UID;
    cout << "Input percent: ";
    cin >> Acc.percent;
    cout << "Input sum: ";
    cin >> Acc.sum;
}

void Display(const AccountData &Acc)
{
    cout << "last_name: " << Acc.last_name 
         << " |UID: " << Acc.UID << " |percent: " 
         << Acc.percent << " |sum: " << Acc.sum << endl;
}

string toString()
{
    return "<Class Account{last_name, UID, percent, sum}>";
}

int main()
{
    AccountData account;
    Read(account);
    Display(account);
    cout << toString() << endl;
    cout << ShowInEuro(account, 65) << endl;
    cout << ShowInDollar(account, 70) << endl;
    cout << ShowSumInNumeral(account) << endl;
    AddSum(account, 90);
    Display(account);
    GetSum(account, 80);
    Display(account);
    ChangeMaster(account, "cat");
    Display(account);
    PlusPetcent(account);
    Display(account);
    return 0;
}