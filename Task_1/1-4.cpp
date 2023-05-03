/* Класс – отрезок. Методы – расчет середины и длины. 
Поля класса – координаты начала, конца, середины и длина.
*/
#include <iostream>
#include <cmath>
using namespace std;

class Section {
private:
    int x1, y1, x2, y2, xm, ym, L;

public:
    Section() {
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;
        xm = 0;
        ym = 0;
        L = 0;
    }

    Section(int a, int b, int c, int d) {
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
    }

    void set();
    void get();
    void display();
    void Middle();
    void Length();

    bool operator==(const Section& other) const;
    bool operator!=(const Section& other) const;
    bool operator<(const Section& other) const;
    bool operator<=(const Section& other) const;
    bool operator>(const Section& other) const;
    bool operator>=(const Section& other) const;

    Section operator+(const Section& other) const;
    Section operator-(const Section& other) const;
};

void Section::set() {
    cout << "x1: ";
    cin >> x1;
    cout << "y1: ";
    cin >> y1;
    cout << "x2: ";
    cin >> x2;
    cout << "y2: ";
    cin >> y2;
}

void Section::get() {
    cout << "The number is: " << x1 << endl;
}

void Section::display() {
    cout << "segment coordinates: (" << x1 << "," << y1 << ")"
         << "(" << x2 << "," << y2 << ")" << endl;
    cout << "segment middle: (" << xm << "," << ym << ")" << endl;
    cout << "segment length: " << L << endl;
}

void Section::Middle() {
    xm = (x1 + x2) / 2;
    ym = (y1 + y2) / 2;
}

void Section::Length() {
    L = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool Section::operator==(const Section& other) const {
    return (x1 == other.x1) && (y1 == other.y1) &&
           (x2 == other.x2) && (y2 == other.y2);
}

bool Section::operator!=(const Section& other) const {
    return !(*this == other);
}

bool Section::operator<(const Section& other) const {
    return L < other.L;
}

bool Section::operator<=(const Section& other) const {
    return L <= other.L;
}

bool Section::operator>(const Section& other) const {
    return L > other.L;
}

bool Section::operator>=(const Section& other) const {
    return L >= other.L;
}

Section Section::operator+(const Section& other) const {
    return Section(x1 + other.x1, y1 + other.y1, x2 + other.x2, y2 + other.y2);
}

Section Section::operator-(const Section& other) const {
    return Section(x1 - other.x1, y1 - other.y1, x2 - other.x2, y2 - other.y2);
}

int main() {
    Section n1, n2;
    n1.set();
    n2.set();
    n1.Middle();
    n1.Length();
    n1.display();

    n2.Middle();
    n2.Length();
    n2.display();
}