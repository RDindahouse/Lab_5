/*Класс – натуральная дробь. Методы класса – сумма, разность, произведение, частное
натуральных дробей. Поля класса – числитель и знаменатель дроби.  */
#include <iostream>
#include <math.h>
using namespace std;

class NatFraction
{
    int nom, denom;

public:
    NatFraction()
    {
        nom = 0;
        denom = 0;
    }

    NatFraction(int r, int i)
    {
        nom = r;
        denom = i;
    }

    int getNom() const
    {
        return nom;
    }

    int getDenom() const
    {
        return denom;
    }

    void setNom(int n)
    {
        nom = n;
    }

    void setDenom(int d)
    {
        denom = d;
    }

    void set()
    {
        cout << "Enter nominator: ";
        cin >> nom;

        do
        {
            cout << "Enter denominator: ";
            cin >> denom;
        } while (denom == 0);
    }

    void get()
    {
        cout << "The number is: " << nom / denom << endl;
    }

    NatFraction operator+(const NatFraction &other)
    {
        int n = nom * other.denom + other.nom * denom;
        int d = denom * other.denom;
        return NatFraction(n, d);
    }

    NatFraction operator-(const NatFraction &other)
    {
        int n = nom * other.denom - other.nom * denom;
        int d = denom * other.denom;
        return NatFraction(n, d);
    }

    NatFraction operator*(const NatFraction &other)
    {
        int n = nom * other.nom;
        int d = denom * other.denom;
        return NatFraction(n, d);
    }

    NatFraction operator/(const NatFraction &other)
    {
        int n = nom * other.denom;
        int d = denom * other.nom;
        return NatFraction(n, d);
    }
};

int main()
{
    NatFraction n1, n2, result;
    n1.set();
    n2.set();
    result = n1 + n2;
    cout << "n1 + n2 = " << result.getNom() << "/" << result.getDenom() << endl;
    result = n1 - n2;
    cout << "n1 - n2 = " << result.getNom() << "/" << result.getDenom() << endl;
    result = n1 * n2;
    cout << "n1 * n2 = " << result.getNom() << "/" << result.getDenom() << endl;
    result = n1 / n2;
    cout << "n1 / n2 = " << result.getNom() << "/" << result.getDenom() << endl;
    return 0;
}