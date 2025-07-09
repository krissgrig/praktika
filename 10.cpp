#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int JUDGES = 10;
const int EVENTS = 3;

float calculateScore(const vector<int>& scores) {
    vector<int> temp = scores;
    sort(temp.begin(), temp.end());
    int sum = 0;
    for (int i = 1; i < JUDGES - 1; ++i) {
        sum += temp[i];
    }
    return static_cast<float>(sum) / (JUDGES - 2);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество участников: ";
    cin >> n;

    vector<vector<vector<int>>> data(n, vector<vector<int>>(EVENTS, vector<int>(JUDGES)));

    for (int i = 0; i < n; ++i) {
        cout << "\nУчастник " << i + 1 << ":\n";
        for (int j = 0; j < EVENTS; ++j) {
            cout << "  Вид " << j + 1 << " (введите " << JUDGES << " оценок): ";
            for (int k = 0; k < JUDGES; ++k) {
                cin >> data[i][j][k];
            }
        }
    }

    int winner = -1;
    float bestScore = -1;

    for (int i = 0; i < n; ++i) {
        float total = 0;
        for (int j = 0; j < EVENTS; ++j) {
            total += calculateScore(data[i][j]);
        }
        cout << "Суммарный балл участника " << i + 1 << ": " << total << "\n";

        if (total > bestScore) {
            bestScore = total;
            winner = i;
        }
    }

    cout << "\nПобедитель: Участник " << winner + 1 << " с результатом " << bestScore << " баллов.\n";

    return 0;
}
