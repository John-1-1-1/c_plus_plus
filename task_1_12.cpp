#include <iostream>
#include <cmath>


using namespace std;


struct Point {

    double x, y;

    void Init(double x_, double y_) {
        x = x_;
        y = y_;
    }

    double distance() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    void Display() {
        cout << "x = " << x << endl
             << "y = " << y << endl;
    }

    void Read() {
        cout << "Input x: ";
        cin >> x;
        cout << "Input y: ";
        cin >> y;
    }
};

Point make_Point(double x, double y) {
    Point point;
    point.Init(x, y);
    return point;
}

int main()
{

    Point point = make_Point(3, 4.1);

    point.Display();

    cout << point.distance() << endl;

    point.Read();
    point.Display();

    cout << point.distance() << endl;

    return 0;
}

