#include <iostream>
#include <cmath>
using namespace std;


int checkIntersection(double R, double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;

    double a = dx*dx + dy*dy;
    double b = 2 * (x1*dx + y1*dy);
    double c = x1*x1 + y1*y1 - R*R;

    double discriminant = b*b - 4*a*c;

    if (discriminant < 0) {
        return 0;
    }

    double sqrtD = sqrt(discriminant);
    double t1 = (-b + sqrtD) / (2*a);
    double t2 = (-b - sqrtD) / (2*a);

    int count = 0;
    if (t1 >= 0 && t1 <= 1) count++;
    if (t2 >= 0 && t2 <= 1 && fabs(t1 - t2) > 1e-8) count++;

    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double R, x1, y1, x2, y2;

    while (true) {
        cout << "Введите радиус окружности R: ";
        cin >> R;
        cout << "Введите координаты x1, y1: ";
        cin >> x1 >> y1;
        cout << "Введите координаты x2, y2: ";
        cin >> x2 >> y2;

        int intersections = checkIntersection(R, x1, y1, x2, y2);

        switch (intersections) {
            case 0:
                cout << "Отрезок не пересекает окружность.\n";
                break;
            case 1:
                cout << "Отрезок касается окружности.\n";
                break;
            case 2:
                cout << "Отрезок пересекает окружность в двух точках.\n";
                break;
            default:
                cout << "Ошибка.\n";
        }

        char again;
        cout << "Проверить ещё раз? (y/n): ";
        cin >> again;
        if (again != 'y' && again != 'Y') break;
    }

    return 0;
}
