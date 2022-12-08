#include <iostream>
#include <cmath>
using namespace std;

class Sum{
public:

    float sum;
    float percent;

    Sum(float sum, float percent){
       this->sum = sum;
       this->percent = percent;
    }

    Sum() {
        sum = 0.0;
        percent = 0.0;
    }

#pragma region Operations with Sum

    bool GetSum(float _sum)
    {
        if (_sum <= 0 || _sum > sum)
        {
            return false;
        }
        sum -= _sum;
        return true;
    }

    bool AddSum(float _sum)
    {
        if (_sum <= 0)
        {
            return false;
        }

        sum += _sum;
        return true;
    }

     void PlusPercent()
    {
        sum += sum * percent;
    }

    float ShowInEuro(float Euro) const
    {
        return sum / Euro;
    }

    float ShowInDollar(float Dollar) const
    {
        return sum / Dollar;
    }

    int ShowSumInNumeral() const
    {
        return (int)sum;
    }
#pragma endregion

};

class Account
{
private:
    string last_name;
    string UID;
public:
    Sum summa;

    Account(string _last_name, string _uid, float _percent, float _sum)
    {
        last_name = _last_name;
        UID = _uid;
        summa = Sum(_sum, _percent);
    }

    bool ChangeMaster(const string& _last_name)
    {
        if (_last_name.empty())
        {
            return false;
        }
        last_name = _last_name;
        return true;
    }

    void Display()
    {
        cout << "last_name: " << last_name << " |UID: " << UID;
        cout << " |sum: " << summa.sum << " |percent: " << summa.percent << endl;
    }
};
int main()
{
    Account account("", "", 12, 1200);
    account.Display();
    cout << account.summa.ShowInEuro(65) << endl;
    cout << account.summa.ShowInDollar(70) << endl;
    cout << account.summa.ShowSumInNumeral() << endl;
    account.summa.AddSum(90);
    account.Display();
    account.summa.GetSum(80);
    account.Display();
    account.ChangeMaster("cat");
    account.Display();
    account.summa.PlusPercent();
    account.Display();
    return 0;
}





