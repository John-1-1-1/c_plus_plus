#include <iostream>
#include <cmath>
using namespace std;

class MetaData{
    public:
    string last_name;
    string UID;
    float percent;
    float sum;
    void Init(string _last_name, string _UID, float _percent, float _sum){
        last_name = _last_name;
        UID = _UID;
        percent = _percent;
        sum = _sum;
    }
    void Read() {
        cout << "Input last_name: ";
        cin >> last_name;
        cout << "Input UID: ";
        cin >> UID;
        cout << "Input percent: ";
        cin >> percent;
        cout << "Input sum: ";
        cin >> sum;
    }
    void Display(){
        cout << "last_name: " << last_name <<
                " |UID: " << UID << " |percent: " << percent <<
                " |sum: " << sum << endl;
    }
    string toString(){
         return "<Class MetaData{last_name, UID, percent, sum}>"; 
    }
};

class Account{
public:
    MetaData meta;
    
    Account(){
        meta.Read();
    }
    Account(string _last_name, string _UID, float _percent, float _sum){
        meta.Init(_last_name, _UID, _percent, _sum);
    }
    bool ChangeMaster(string _last_name){   
        if (_last_name == ""){
            return false;
        }
        meta.last_name = _last_name;
        return true;
    }
    bool GetSum(float _sum){
        if (_sum <= 0 || _sum > meta.sum){
            return false;
        }
        meta.sum -= _sum;
        return true;        
    }
    bool AddSum(float _sum){
        if (_sum <= 0){
            return false;
        }
        meta.sum += _sum;
        return true;
    }
    void PlusPetcent(){
        meta.sum += meta.sum * meta.percent;
    }
    float ShowInEuro(float Euro){
        return meta.sum/ Euro;
    }
    float ShowInDollar(float Dollar){
        return meta.sum/ Dollar;
    }
    int ShowSumInNumeral(){
        return meta.sum;
    }
};
int main(){
    Account account;
    account.meta.Display();
    cout << account.meta.toString() << endl;
    cout << account.ShowInEuro(65) << endl;
    cout << account.ShowInDollar(70) << endl;
    cout << account.ShowSumInNumeral() << endl;
    account.AddSum(90);
    account.meta.Display();
    account.GetSum(80);
    account.meta.Display();
    account.ChangeMaster("cat");
    account.meta.Display();
    account.PlusPetcent();
    account.meta.Display();
    return 0;
}