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
        cout << "Введите длины сторон a, b, c: ";
        cin >> a >> b >> c;

        if (Is_Tri(a, b, c)) {
            cout << "Треугольник с такими сторонами можно построить.\n";
        } else {
            cout << "Треугольник с такими сторонами построить нельзя.\n";
        }

        cout << "Проверить другие значения? (д/н): ";
        cin >> repeat;
    } while (repeat == 'д' || repeat == 'Д');

    return 0;
}
