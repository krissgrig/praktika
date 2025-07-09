#include <iostream>
#include <iomanip>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double V, t1, t2;
    const double g = 9.8;

    cout << "������� ��������� �������� V (�/�): ";
    cin >> V;
    cout << "������� ����� t1 (���): ";
    cin >> t1;
    cout << "������� ����� t2 (���): ";
    cin >> t2;

    double s1 = V * t1 - 0.5 * g * t1 * t1;
    double s2 = V * t2 - 0.5 * g * t2 * t2;

    cout << fixed << setprecision(2);
    cout << "���������� � ������ t1: " << s1 << " �" << endl;
    cout << "���������� � ������ t2: " << s2 << " �" << endl;

    return 0;
}
