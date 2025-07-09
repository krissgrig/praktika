#include <iostream>
#include <iomanip>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double V, t1, t2;
    const double g = 9.8;

    cout << "Введите начальную скорость V (м/с): ";
    cin >> V;
    cout << "Введите время t1 (сек): ";
    cin >> t1;
    cout << "Введите время t2 (сек): ";
    cin >> t2;

    double s1 = V * t1 - 0.5 * g * t1 * t1;
    double s2 = V * t2 - 0.5 * g * t2 * t2;

    cout << fixed << setprecision(2);
    cout << "Расстояние в момент t1: " << s1 << " м" << endl;
    cout << "Расстояние в момент t2: " << s2 << " м" << endl;

    return 0;
}
