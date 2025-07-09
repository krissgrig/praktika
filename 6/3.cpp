#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generateRandomArray(int* arr, int size, int minVal = -50, int maxVal = 50) {
    for (int i = 0; i < size; ++i) {
        *(arr + i) = minVal + rand() % (maxVal - minVal + 1);
    }
}

void printArray(int* arr, int size, const string& name = "Массив") {
    cout << name << ": ";
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void splitArray(int* source, int size, int* positive, int* negative, int* posSize, int* negSize) {
    *posSize = 0;
    *negSize = 0;
    for (int i = 0; i < size; ++i) {
        if (*(source + i) > 0) {
            *(positive + (*posSize)) = *(source + i);
            (*posSize)++;
        } else if (*(source + i) < 0) {
            *(negative + (*negSize)) = *(source + i);
            (*negSize)++;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    const int SIZE = 20;
    int array[SIZE];
    int positive[SIZE], negative[SIZE];
    int posSize, negSize;

    generateRandomArray(array, SIZE);
    printArray(array, SIZE, "Исходный массив");

    splitArray(array, SIZE, positive, negative, &posSize, &negSize);

    printArray(positive, posSize, "Положительные значения");
    printArray(negative, negSize, "Отрицательные значения");

    return 0;
}
