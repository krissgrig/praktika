#include <iostream>
using namespace std;

void inputArray(int arr[], int &size) {
    cout << "Введите количество элементов массива: ";
    cin >> size;
    cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

void printArray(int arr[], int size) {
    cout << "Массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMaxIndex(int arr[], int size) {
    int maxIdx = 0;
    for (int i = 1; i < size; ++i)
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    return maxIdx;
}

int findMinIndex(int arr[], int size) {
    int minIdx = 0;
    for (int i = 1; i < size; ++i)
        if (arr[i] < arr[minIdx]) minIdx = i;
    return minIdx;
}

void deleteByIndex(int arr[], int &size, int index) {
    for (int i = index; i < size - 1; ++i)
        arr[i] = arr[i + 1];
    --size;
}

void deleteMinMax(int arr[], int &size) {
    int maxIdx = findMaxIndex(arr, size);
    int minIdx = findMinIndex(arr, size);

    if (maxIdx > minIdx) {
        deleteByIndex(arr, size, maxIdx);
        deleteByIndex(arr, size, minIdx);
    } else {
        deleteByIndex(arr, size, minIdx);
        deleteByIndex(arr, size, maxIdx);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size;

    inputArray(arr, size);
    printArray(arr, size);

    deleteMinMax(arr, size);
    cout << "После удаления минимального и максимального элементов:" << endl;
    printArray(arr, size);

    return 0;
}
