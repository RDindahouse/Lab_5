/*Класс – десятичная дробь. Методы класса – сумма, разность, произведение, частное
десятичных дробей. Поля класса – целая и дробная часть числа. */
#include <iostream>
#include <math.h>
using namespace std;

class Fraction
{
    double nom, denom;

public:
    Fraction()
    {
        nom = 0;
        denom = 0;
    }
    Fraction(int r, int i)
    {
        nom = r;
        denom = i;
    }
    void set();
    void get();
    void display();

    // operator overloading
    Fraction operator+(Fraction const &obj)
    {
        Fraction res;
        res.nom = nom * obj.denom + obj.nom * denom;
        res.denom = denom * obj.denom;
        return res;
    }

    Fraction operator-(Fraction const &obj)
    {
        Fraction res;
        res.nom = nom * obj.denom - obj.nom * denom;
        res.denom = denom * obj.denom;
        return res;
    }

    Fraction operator*(Fraction const &obj)
    {
        Fraction res;
        res.nom = nom * obj.nom;
        res.denom = denom * obj.denom;
        return res;
    }

    Fraction operator/(Fraction const &obj)
    {
        Fraction res;
        res.nom = nom * obj.denom;
        res.denom = denom * obj.nom;
        return res;
    }
};

void Fraction::set()
{
    cout << "Enter nominator: ";
    cin >> nom;
    cout << "Enter denominator: ";
    cin >> denom;
}

void Fraction::get()
{
    cout << "The number is: " << nom / denom << endl;
}

main()
{
    Fraction n1, n2;
    Fraction result;
    n1.set();
    n2.set();

    result = n1 + n2;
    cout << "n1 + n2 = ";
    result.get();

    result = n1 - n2;
    cout << "n1 - n2 = ";
    result.get();

    result = n1 * n2;
    cout << "n1 * n2 = ";
    result.get();

    result = n1 / n2;
    cout << "n1 / n2 = ";
    result.get();
}