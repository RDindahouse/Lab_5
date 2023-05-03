/*
Класс – треугольник. Методы – расчет площади и периметра треугольника.
Поля – стороны треугольника.
*/
#include <iostream>
#include <cmath>
#define pi 3.1415926535
using namespace std;

class Triangle
{
    int a, b, c;
    double S, P;

public:
    Triangle() : a(0), b(0), c(0), P(0), S(0)
    {
    }
    Triangle(int x, int y, int z) : a(x), b(y), c(z)
    {
        S = 0;
        P = 0;
    }

    void set();
    void get();
    void display();
    void Area();
    void perimeter();

    Triangle &operator=(const Triangle &);
    Triangle operator+(const Triangle &) const;
    Triangle operator-(const Triangle &) const;
    Triangle operator*(const int &) const;
    bool operator==(const Triangle &) const;
};

void Triangle::set()
{
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
}

void Triangle::get()
{
    cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
}

void Triangle::display()
{
    cout << "triangle area: " << S << endl;
    cout << "triangle perimeter: " << P << endl;
}

void Triangle::Area()
{
    double p;
    p = (a + b + c) / 2;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::perimeter()
{
    P = a + b + c;
}

Triangle &Triangle::operator=(const Triangle &other)
{
    if (this != &other)
    {
        a = other.a;
        b = other.b;
        c = other.c;
        S = other.S;
        P = other.P;
    }
    return *this;
}

Triangle Triangle::operator+(const Triangle &other) const
{
    int x = a + other.a;
    int y = b + other.b;
    int z = c + other.c;
    return Triangle(x, y, z);
}

Triangle Triangle::operator-(const Triangle &other) const
{
    int x = a - other.a;
    int y = b - other.b;
    int z = c - other.c;
    return Triangle(x, y, z);
}

Triangle Triangle::operator*(const int &num) const
{
    int x = a * num;
    int y = b * num;
    int z = c * num;
    return Triangle(x, y, z);
}

bool Triangle::operator==(const Triangle &other) const
{
    return (a == other.a) && (b == other.b) && (c == other.c);
}

int main()
{
    Triangle t1, t2;
    t1.set();
    t1.Area();
    t1.perimeter();
    t1.display();

    cout << "Enter values for another triangle:" << endl;
    t2.set();
    t2.Area();
    t2.perimeter();
    t2.display();

    Triangle t3 = t1 + t2;
    cout << "t1 + t2 = ";
    t3.get();

    Triangle t4 = t2 - t1;
    cout << "t2 - t1 = ";
    t4.get();

    int num = 3;
    Triangle t5 = t1 * num;
    cout << "t1 * " << num << "= ";
    t5.get();

    cin.get();
};
