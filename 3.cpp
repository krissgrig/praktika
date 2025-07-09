#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i;
    }
    return sum == n;
}

int main() {
    setlocale(LC_ALL, "Russian");
    char repeat;
    do {
        int N;
        cout << "������� ����������� �����: ";
        cin >> N;

        if (isPrime(N)) {
            cout << N << " � ������� �����.\n";
        } else {
            if (isPerfect(N))
                cout << N << " � ����������� �����.\n";
            else
                cout << N << " � �� �������� �� �������, �� �����������.\n";
        }

        cout << "������ ��������� ������ �����? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
