/*
Класс – шар. Методы – расчет площади и объема шара. 
Поля – координаты
центра (x, y, z), радиус шара.
*/
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

class Sphere {
private:
    double x, y, z;
    double radius;

public:
    Sphere() : x(0), y(0), z(0), radius(0) {}

    Sphere(double x, double y, double z, double radius)
        : x(x), y(y), z(z), radius(radius) {}

    double getRadius() const { return radius; }

    double getX() const { return x; }

    double getY() const { return y; }

    double getZ() const { return z; }

    double getArea() const { return 4 * M_PI * radius * radius; }

    double getVolume() const { return 4.0 / 3.0 * M_PI * radius * radius * radius; }

    Sphere operator+(const Sphere& other) const {
        double new_x = x + other.x;
        double new_y = y + other.y;
        double new_z = z + other.z;
        double new_radius = radius + other.radius;
        return Sphere(new_x, new_y, new_z, new_radius);
    }

    Sphere operator-(const Sphere& other) const {
        double new_x = x - other.x;
        double new_y = y - other.y;
        double new_z = z - other.z;
        double new_radius = abs(radius - other.radius);
        return Sphere(new_x, new_y, new_z, new_radius);
    }

    Sphere operator*(double factor) const {
        double new_radius = radius * factor;
        return Sphere(x, y, z, new_radius);
    }

    Sphere operator/(double divisor) const {
        double new_radius = radius / divisor;
        return Sphere(x, y, z, new_radius);
    }

    bool operator==(const Sphere& other) const {
        return x == other.x && y == other.y && z == other.z && radius == other.radius;
    }

    bool operator!=(const Sphere& other) const { return !(*this == other); }
};

int main() {
    Sphere s1(0, 0, 0, 5);
    Sphere s2(3, 3, 3, 2);

    Sphere s3 = s1 + s2;
    Sphere s4 = s1 - s2;
    Sphere s5 = s1 * 2;
    Sphere s6 = s1 / 2;

    cout << "s1 radius: " << s1.getRadius() << endl;
    cout << "s2 area: " << s2.getArea() << endl;
    cout << "s3 volume: " << s3.getVolume() << endl;
    cout << "s4 center: (" << s4.getX() << ", " << s4.getY() << ", " << s4.getZ() << ")" << endl;
    cout << "s5 radius: " << s5.getRadius() << endl;
    cout << "s6 volume: " << s6.getVolume() << endl;

    if (s1 == s2) {
        cout << "s1 is equal to s2" << endl;
    }
    else {
        std::cout << "s1 is not equal to s2" << endl;
    }

    return 0;
}