/*
Класс – параллелепипед. Методы – расчет площади поверхности и объема параллелепипеда.
Поля – ребра a , b , c , площадь и объем.
*/
#include <iostream>
#include <cmath>
#define pi 3.1415926535
using namespace std;
class Parallelepiped
{
private:
    double a, b, c;
    double S, V;

public:
    Parallelepiped()
    {
        a = b = c = S = V = 0;
    }

    Parallelepiped(double x, double y, double z)
    {
        a = x;
        b = y;
        c = z;
        calculateArea();
        calculateVolume();
    }

    double getA() const
    {
        return a;
    }

    double getB() const
    {
        return b;
    }

    double getC() const
    {
        return c;
    }

    double getArea() const
    {
        return S;
    }

    double getVolume() const
    {
        return V;
    }

    void display() const
    {
        cout << "first edge: " << a << endl;
        cout << "second edge: " << b << endl;
        cout << "third edge: " << c << endl;
        cout << "Volume: " << V << endl;
        cout << "Area: " << S << endl;
    }

    void set()
    {
        cout << "Enter the length of the first edge: ";
        cin >> a;
        cout << "Enter the length of the second edge: ";
        cin >> b;
        cout << "Enter the length of the third edge: ";
        cin >> c;
        calculateArea();
        calculateVolume();
    }

    void calculateArea()
    {
        S = 2 * (a * b + a * c + b * c);
    }

    void calculateVolume()
    {
        V = a * b * c;
    }

    Parallelepiped &operator=(const Parallelepiped &other)
    {
        a = other.a;
        b = other.b;
        c = other.c;
        S = other.S;
        V = other.V;
        return *this;
    }

    Parallelepiped operator+(const Parallelepiped &other) const
    {
        return Parallelepiped(a + other.a, b + other.b, c + other.c);
    }

    Parallelepiped operator-(const Parallelepiped &other) const
    {
        return Parallelepiped(a - other.a, b - other.b, c - other.c);
    }

    Parallelepiped operator*(double k) const
    {
        return Parallelepiped(a * k, b * k, c * k);
    }

    Parallelepiped operator/(double k) const
    {
        return Parallelepiped(a / k, b / k, c / k);
    }

    bool operator==(const Parallelepiped &other) const
    {
        return a == other.a && b == other.b && c == other.c;
    }

    bool operator!=(const Parallelepiped &other) const
    {
        return !(*this == other);
    }

    bool operator>(const Parallelepiped &other) const
    {
        return V > other.V;
    }

    bool operator<(const Parallelepiped &other) const
    {
        return V < other.V;
    }

    bool operator>=(const Parallelepiped &other) const
    {
        return V >= other.V;
    }

    bool operator<=(const Parallelepiped &other) const
    {
        return V <= other.V;
    }
};
int main()
{
    Parallelepiped n1;
    double result;
    n1.set();
    n1.display();
}