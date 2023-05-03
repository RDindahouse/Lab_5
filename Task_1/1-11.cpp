/*Класс – трапеция. Методы – расчет площади и периметра трапеции.
Поля – стороны трапеции, площадь и периметр.*/
#include <iostream>
#include <cmath>
#define pi 3.1415926535
using namespace std;

class Trapezoid {
    int a, b, c, d;
    double S, P;

public:
    Trapezoid() {
        // Базовый конструктор
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        P = 0;
        S = 0;
    }

    Trapezoid(int x, int y, int b, int f, double d, double e) {
        // конструктор с параметрами
        a = x;
        b = b;
        c = c;
        d = f;
        S = d;
        P = e;
    }

    // Перегрузка оператора присваивания
    Trapezoid& operator=(const Trapezoid& other) {
        a = other.a;
        b = other.b;
        c = other.c;
        d = other.d;
        S = other.S;
        P = other.P;
        return *this;
    }

    // Перегрузка оператора сложения
    Trapezoid operator+(const Trapezoid& other) const {
        Trapezoid res;
        res.a = a + other.a;
        res.b = b + other.b;
        res.c = c + other.c;
        res.d = d + other.d;
        res.Area();
        res.perimeter();
        return res;
    }

    // Перегрузка оператора вычитания
    Trapezoid operator-(const Trapezoid& other) const {
        Trapezoid res;
        res.a = a - other.a;
        res.b = b - other.b;
        res.c = c - other.c;
        res.d = d - other.d;
        res.Area();
        res.perimeter();
        return res;
    }

    // Перегрузка оператора умножения
    Trapezoid operator*(int n) const {
        Trapezoid res;
        res.a = a * n;
        res.b = b * n;
        res.c = c * n;
        res.d = d * n;
        res.Area();
        res.perimeter();
        return res;
    }

    // Перегрузка оператора деления
    Trapezoid operator/(int n) const {
        Trapezoid res;
        res.a = a / n;
        res.b = b / n;
        res.c = c / n;
        res.d = d / n;
        res.Area();
        res.perimeter();
        return res;
    }

    // Перегрузка оператора равенства
    bool operator==(const Trapezoid& other) const {
        return a == other.a && b == other.b && c == other.c && d == other.d;
    }

    // Методы класса
    void set();
    void get();
    void display();
    void Area();
    void perimeter();
};


void Trapezoid::set()
{ // Метод присвоения
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    cout << "d: ";
    cin >> d;
}

void Trapezoid::get()
{
    cout << "The number is: " << a << endl;
}

void Trapezoid::display()
{
    cout << "triangle area: " << S << endl;
    cout << "triangle perimeter: " << P << endl;
}

void Trapezoid::Area()
{ // Площадь параллелепипеда
    S = (a + b) / 2 * sqrt(pow(c, 2) - ((pow(b - a, 2) + pow(c, 2) - pow(d, 2)) / (2 * (b - a))));
}

void Trapezoid::perimeter()
{ // Периметр треугольника
    P = a + b + c + d;
}

main()
{
    Trapezoid n1;
    double result;
    n1.set();
    n1.Area();
    n1.perimeter();
    n1.display();
}