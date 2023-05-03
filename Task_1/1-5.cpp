/*
Класс – окружность. Методы – расчет длины окружности и ее площади.
Поля класса – координаты центра, радиус, длина, площадь окружности.
*/
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846
using namespace std;

class Circle
{
    double x, y, r, length, area;

public:
    Circle(double _x = 0, double _y = 0, double _r = 0) : x(_x), y(_y), r(_r), length(0), area(0) {}
    void set()
    {
        cout << "Enter center coordinates: ";
        cin >> x >> y;
        cout << "Enter radius: ";
        cin >> r;
    }
    void calcLength()
    {
        length = 2 * M_PI * r;
    }
    void calcArea()
    {
        area = M_PI * r * r;
    }
    void display()
    {
        cout << "Center: (" << x << ", " << y << ")" << endl;
        cout << "Radius: " << r << endl;
        if (length > 0)
            cout << "Length: " << length << endl;
        if (area > 0)
            cout << "Area: " << area << endl;
    }
    Circle operator+(const Circle &c)
    {
        Circle res;
        res.x = x + c.x;
        res.y = y + c.y;
        res.r = r + c.r;
        return res;
    }
    Circle operator-(const Circle &c)
    {
        Circle res;
        res.x = x - c.x;
        res.y = y - c.y;
        res.r = r - c.r;
        return res;
    }
    Circle operator*(const Circle &c)
    {
        Circle res;
        res.x = x * c.x;
        res.y = y * c.y;
        res.r = r * c.r;
        return res;
    }
    Circle operator/(const Circle &c)
    {
        Circle res;
        res.x = x / c.x;
        res.y = y / c.y;
        res.r = r / c.r;
        return res;
    }
    bool operator==(const Circle &c)
    {
        return (x == c.x && y == c.y && r == c.r);
    }
    bool operator!=(const Circle &c)
    {
        return (x != c.x || y != c.y || r != c.r);
    }
    bool operator>(const Circle &c)
    {
        return (r > c.r);
    }
    bool operator<(const Circle &c)
    {
        return (r < c.r);
    }
};

int main()
{
    Circle c1, c2, res;
    c1.set();
    c1.calcLength();
    c1.calcArea();
    c1.display();
    c2.set();
    c2.calcLength();
    c2.calcArea();
    c2.display();
    res = c1 + c2;
    res.display();
    res = c1 - c2;
    res.display();
    res = c1 * c2;
    res.display();
    res = c1 / c2;
    res.display();
    if (c1 == c2)
    {
        cout << "c1 and c2 are equal" << endl;
    }
    if (c1 != c2)
    {
        cout << "c1 and c2 are not equal" << endl;
    }
    if (c1 > c2)
    {
        cout << "c1 is larger than c2" << endl;
    }
    if (c1 < c2)
    {
        cout << "c1 is smaller than c2" << endl;
    }
    return 0;
}