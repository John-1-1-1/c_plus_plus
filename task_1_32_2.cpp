#include <iostream>
#include <cmath>
using namespace std;

class Account
{
private:
    string last_name;
    string UID;
    float percent;
    float sum;

public:
    void Init(string _last_name, string _UID, float _percent, float _sum)
    {
        last_name = _last_name;
        UID = _UID;
        percent = _percent;
        sum = _sum;
    }

    bool ChangeMaster(string _last_name)
    {
        if (_last_name == "")
        {
            return false;
        }
        last_name = _last_name;
        return true;
    }

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
    void PlusPetcent()
    {
        sum += sum * percent;
    }
    float ShowInEuro(float Euro)
    {
        return sum / Euro;
    }
    float ShowInDollar(float Dollar)
    {
        return sum / Dollar;
    }
    int ShowSumInNumeral()
    {
        return sum;
    }
    void Read()
    {
        cout << "Input last_name: ";
        cin >> last_name;
        cout << "Input UID: ";
        cin >> UID;
        cout << "Input percent: ";
        cin >> percent;
        cout << "Input sum: ";
        cin >> sum;
    }
    void Display()
    {
        cout << "last_name: " << last_name << " |UID: " << UID << " |percent: " << percent << " |sum: " << sum << endl;
    }
    string toString()
    {
        return "<Class Account{last_name, UID, percent, sum}>";
    }
};
int main()
{
    Account account;
    account.Read();
    account.Display();
    cout << account.toString() << endl;
    cout << account.ShowInEuro(65) << endl;
    cout << account.ShowInDollar(70) << endl;
    cout << account.ShowSumInNumeral() << endl;
    account.AddSum(90);
    account.Display();
    account.GetSum(80);
    account.Display();
    account.ChangeMaster("cat");
    account.Display();
    account.PlusPetcent();
    account.Display();
    return 0;
}





