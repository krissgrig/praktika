#include <iostream>
#include <cstring>
#include <cctype>  // для isalpha
using namespace std;

int countWords(const char* str) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (isalpha(str[i])) {
            if (!inWord) {
                inWord = true;
                count++;
            }
        } else {
            inWord = false;
        }
    }

    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int SIZE = 256;
    char input[SIZE];

    cout << "Введите строку: ";
    cin.getline(input, SIZE);

    int wordCount = countWords(input);

    cout << "Количество слов: " << wordCount << endl;

    return 0;
}
