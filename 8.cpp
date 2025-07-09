#include <iostream>
#include <iomanip>

using namespace std;

const double PI = 3.141592653589793;

double calculateVolume(double r, double h) {
    return (1.0 / 3.0) * PI * r * r * h;
}

double calculateSurfaceArea(double r, double l) {
    return PI * r * (r + l);
}

int findMaxIndex(double arr[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; ++i)
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    return maxIndex;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 4;
    double cones[n][5] = {
        {3.0, 5.0, 5.83},
        {2.5, 4.0, 4.72},
        {4.0, 6.0, 7.21},
        {3.5, 4.5, 5.31}
    };

    double volumes[n];
    double areas[n];

    for (int i = 0; i < n; ++i) {
        double r = cones[i][0];
        double h = cones[i][1];
        double l = cones[i][2];

        double volume = calculateVolume(r, h);
        double area = calculateSurfaceArea(r, l);

        cones[i][3] = volume;
        cones[i][4] = area;

        volumes[i] = volume;
        areas[i] = area;
    }

    int maxVolumeIndex = findMaxIndex(volumes, n);
    int maxAreaIndex = findMaxIndex(areas, n);

    cout << fixed << setprecision(2);
    cout << "Конусы (r, h, l, V, S):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Конус " << i + 1 << ": ";
        for (int j = 0; j < 5; ++j)
            cout << cones[i][j] << " ";
        cout << endl;
    }

    cout << "\nКонус с наибольшим объемом: Конус " << maxVolumeIndex + 1 << endl;
    cout << "Конус с наибольшей площадью: Конус " << maxAreaIndex + 1 << endl;

    return 0;
}
