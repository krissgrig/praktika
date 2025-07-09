#include <iostream>
using namespace std;

int findMaxIndex(int arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int findMinIndex(int arr[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int size = 10;
    int arr[size] = {5, 2, 9, 1, 7, 3, 8, 0, 4, 6};

    int maxIdx = findMaxIndex(arr, size);
    int minIdx = findMinIndex(arr, size);

    cout << "������: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "������ ����������� ��������: " << maxIdx << " (�������� = " << arr[maxIdx] << ")" << endl;
    cout << "������ ����������� ��������: " << minIdx << " (�������� = " << arr[minIdx] << ")" << endl;

    return 0;
}
