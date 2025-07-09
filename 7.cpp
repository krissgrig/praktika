#include <iostream>
#include <iomanip>  // дл€ std::setprecision
#include <cmath>    // дл€ std::abs

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double consumption[12] = {120.5, 110.3, 130.7, 125.0, 140.2, 150.6, 160.9, 155.4, 145.1, 135.0, 128.6, 118.9};

    double sum = 0;
    double minVal = consumption[0];
    double maxVal = consumption[0];

    for (int i = 0; i < 12; ++i) {
        sum += consumption[i];
        if (consumption[i] < minVal)
            minVal = consumption[i];
        if (consumption[i] > maxVal)
            maxVal = consumption[i];
    }

    double average = sum / 12.0;

    double minDiffPercent = fabs((minVal - average) / average * 100.0);
    double maxDiffPercent = fabs((maxVal - average) / average * 100.0);

    cout << fixed << setprecision(2);
    cout << "—редний расход: " << average << " к¬тЈч" << endl;
    cout << "ћинимальный расход: " << minVal << " к¬тЈч (" << minDiffPercent << "% от среднего)" << endl;
    cout << "ћаксимальный расход: " << maxVal << " к¬тЈч (" << maxDiffPercent << "% от среднего)" << endl;

    return 0;
}
