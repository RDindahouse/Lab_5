/*
Класс – целочисленный вектор фиксированной размерности. 
Методы – сумма, разность, скалярное произведение векторов, 
сравнение двух векторов на равенство, вычисление длины вектора. 
Поля – размерность вектора, координаты вектора.
*/
#include <iostream>
#include <conio.h>
using namespace std;

class Vector
{
private:
    int x;
    int y;
    int z;

public:
    Vector() : x(0), y(0), z(0)
    {
    }
    Vector(int vx, int vy, int vz) : x(vx), y(vy), z(vz)
    {
    }
    void showVector()
    {
        cout << x << ":" << y << ":" << z << "";
    }
    void showProizVector()
    {
        cout << x + y + z << "";
    }

    Vector operator+(Vector) const;
    Vector operator%(Vector) const;
    Vector operator-(Vector) const;
    bool operator==(const Vector& other) const;
    bool operator<(const Vector& other) const;
    bool operator>(const Vector& other) const;
    bool operator<=(const Vector& other) const;
    bool operator>=(const Vector& other) const;
};
// Сложение
Vector Vector ::operator+(Vector d2) const
{
    int vx = x + d2.x;
    int vy = y + d2.y;
    int vz = z + d2.z;
    return Vector(vx, vy, vz);
}
// Скалярное произведение
Vector Vector ::operator%(Vector d2) const
{
    int vx = x * d2.x;
    int vy = y * d2.y;
    int vz = z * d2.z;
    return Vector((vx + vy + vz), vx * 0, vy * 0);
}

bool Vector::operator==(const Vector& other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool Vector::operator<(const Vector& other) const {
    if (x < other.x) return true;
    if (x > other.x) return false;
    if (y < other.y) return true;
    if (y > other.y) return false;
    return z < other.z;
}

bool Vector::operator>(const Vector& other) const {
    if (x > other.x) return true;
    if (x < other.x) return false;
    if (y > other.y) return true;
    if (y < other.y) return false;
    return z > other.z;
}

bool Vector::operator<=(const Vector& other) const {
    return *this < other || *this == other;
}

bool Vector::operator>=(const Vector& other) const {
    return *this > other || *this == other;
}

// Разность
Vector Vector ::operator-(Vector d2) const
{
    int vx = x - d2.x;
    int vy = y - d2.y;
    int vz = z - d2.z;
    return Vector(vx, vy, vz);
}


int main()
{
    int x, y, z, i, j, k;
    Vector a, b, c;
    cout << "vector a (x, y, z): ";
    cin >> x >> y >> z;
    cout << "vector b (x, y, z): ";
    cin >> i >> j >> k;
    a = Vector(x, y, z);
    b = Vector(i, j, k);
    c = a + b;
    cout << "Addition a(";
    a.showVector();
    cout << ") + b(";
    b.showVector();
    cout << ") = c(";
    c.showVector();
    cout << ")" << endl;
    c = a % b;
    cout << "scalar product a(";
    a.showVector();
    cout << ") % b(";
    b.showVector();
    cout << ") = ";
    c.showProizVector();
    cout << endl;
    c = a - b;
    cout << "difference a(";
    a.showVector();
    cout << ") * b(";
    b.showVector();
    cout << ") = ";
    c.showProizVector();
    cout << endl;

    cin.get();
    return 0;
}