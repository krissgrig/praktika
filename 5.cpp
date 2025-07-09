#include <iostream>
using namespace std;

bool Is_Tri(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, c;
    char repeat;

    do {
        cout << "������� ����� ������ a, b, c: ";
        cin >> a >> b >> c;

        if (Is_Tri(a, b, c)) {
            cout << "����������� � ������ ��������� ����� ���������.\n";
        } else {
            cout << "����������� � ������ ��������� ��������� ������.\n";
        }

        cout << "��������� ������ ��������? (�/�): ";
        cin >> repeat;
    } while (repeat == '�' || repeat == '�');

    return 0;
}
