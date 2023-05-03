/*Класс – комплексное число. Методы – сумма, разность, произведение комплексных
чисел. Поля – действительная и мнимая часть комплексного числа. */
#include <iostream>
#include <math.h>

using namespace std;

class complex
{
    int real, img;

public:
    complex()
    {
        real = 0;
        img = 0;
    }
    complex(int r, int i)
    {
        real = r;
        img = i;
    }
    void set();
    void get();
    void display();
    complex operator+(const complex &other);
    complex operator-(const complex &other);
    complex operator*(const complex &other);
};

void complex::set()
{
    cout << "Enter Real part: ";
    cin >> real;
    cout << "Enter Imaginary Part: ";
    cin >> img;
}

void complex::get()
{
    cout << "The complex number is: " << real << "+" << img << "i" << endl;
}

void complex::display()
{
    if (img < 0)
        if (img == -1)
            cout << "The complex number is: " << real << "-i" << endl;
        else
            cout << "The complex number is: " << real << img << "i" << endl;
    else if (img == 1)
        cout << "The complex number is: " << real << " + i" << endl;
    else
        cout << "The complex number is: " << real << " + " << img << "i" << endl;
}

complex complex::operator+(const complex &other)
{
    complex res;
    res.real = real + other.real;
    res.img = img + other.img;
    return res;
}

complex complex::operator-(const complex &other)
{
    complex res;
    res.real = real - other.real;
    res.img = img - other.img;
    return res;
}

complex complex::operator*(const complex &other)
{
    complex res;
    res.real = real * other.real - img * other.img;
    res.img = img * other.real + real * other.img;
    return res;
}

int main()
{
    complex n1, n2;
    complex result;
    n1.set();
    n2.set();
    result = n1 + n2;
    result.display();
    result = n1 - n2;
    result.display();
    result = n1 * n2;
    result.display();
    return 0;
}