/*
Класс – конус. Методы – расчет площади и объема конуса. 
Поля – радиус основания, высота конуса.
*/
#include <iostream>
#include <cmath>
using namespace std;
#define M_PI 3.14159265358979323846


class Cone {
private:
    double baseRadius;
    double height;
    double area;
    double volume;
    
public:
    Cone() {
        baseRadius = 0;
        height = 0;
        area = 0;
        volume = 0;
    }
    
    Cone(double r, double h) {
        baseRadius = r;
        height = h;
        calculateArea();
        calculateVolume();
    }
    
    void set(double r, double h) {
        baseRadius = r;
        height = h;
        calculateArea();
        calculateVolume();
    }
    
    void get() {
        cout << "Base Radius: " << baseRadius << endl;
        cout << "Height: " << height << endl;
        cout << "Area: " << area << endl;
        cout << "Volume: " << volume << endl << endl;
    }
    
    void calculateArea() {
        double slantHeight = sqrt(pow(baseRadius, 2) + pow(height, 2));
        area = M_PI * baseRadius * slantHeight + M_PI * pow(baseRadius, 2);
    }
    
    void calculateVolume() {
        volume = (1.0/3.0) * M_PI * pow(baseRadius, 2) * height;
    }
    
    Cone operator+(Cone const &c) {
        double r = baseRadius + c.baseRadius;
        double h = height + c.height;
        return Cone(r, h);
    }
    
    Cone operator-(Cone const &c) {
        double r = baseRadius - c.baseRadius;
        double h = height - c.height;
        return Cone(r, h);
    }
    
    Cone operator*(Cone const &c) {
        double r = baseRadius * c.baseRadius;
        double h = height * c.height;
        return Cone(r, h);
    }
    
    Cone operator/(Cone const &c) {
        double r = baseRadius / c.baseRadius;
        double h = height / c.height;
        return Cone(r, h);
    }
    
    bool operator==(Cone const &c) {
        return (baseRadius == c.baseRadius && height == c.height);
    }
    
    bool operator!=(Cone const &c) {
        return (baseRadius != c.baseRadius || height != c.height);
    }
};

int main() {
    Cone c1(2, 3);
    c1.get();
    
    Cone c2(3, 4);
    c2.get();
    
    Cone c3 = c1 + c2;
    c3.get();
    
    Cone c4 = c2 - c1;
    c4.get();
    
    Cone c5 = c1 * c2;
    c5.get();
    
    Cone c6 = c2 / c1;
    c6.get();
    
    if (c1 == c2) {
        cout << "C1 is equal to C2" << endl;
    } else {
        cout << "C1 is not equal to C2" << endl;
    }
    
    if (c1 != c2) {
        cout << "C1 is not equal to C2" << endl;
    } else {
        cout << "C1 is equal to C2" << endl;
    }
    
    return 0;
}