#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    string surname;
    int grade;
    char letter;
};

void addStudent(vector<Student>& students) {
    Student s;
    cout << "Введите имя: ";
    cin >> s.name;
    cout << "Введите фамилию: ";
    cin >> s.surname;
    cout << "Введите номер класса (1-11): ";
    cin >> s.grade;
    cout << "Введите букву класса: ";
    cin >> s.letter;
    students.push_back(s);
}

void printStudent(const Student& s) {
    cout << s.name << " " << s.surname << ", " << s.grade << s.letter << "\n";
}

void printAll(const vector<Student>& students) {
    for (const auto& s : students) {
        printStudent(s);
    }
}

void findDuplicateSurnames(const vector<Student>& students) {
    bool found = false;
    for (size_t i = 0; i < students.size(); ++i) {
        for (size_t j = i + 1; j < students.size(); ++j) {
            if (students[i].surname == students[j].surname) {
                cout << "Однофамильцы: ";
                printStudent(students[i]);
                printStudent(students[j]);
                found = true;
            }
        }
    }
    if (!found)
        cout << "Однофамильцев в школе нет.\n";
}

void findClassDuplicates(const vector<Student>& students) {
    bool found = false;
    for (size_t i = 0; i < students.size(); ++i) {
        for (size_t j = i + 1; j < students.size(); ++j) {
            if (students[i].surname == students[j].surname &&
                students[i].grade == students[j].grade &&
                students[i].letter == students[j].letter) {
                cout << "Однофамильцы в одном классе: ";
                printStudent(students[i]);
                printStudent(students[j]);
                found = true;
            }
        }
    }
    if (!found)
        cout << "В классах однофамильцев нет.\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Student> students;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить ученика\n";
        cout << "2. Вывести всех учеников\n";
        cout << "3. Поиск однофамильцев в школе\n";
        cout << "4. Поиск однофамильцев в одном классе\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: printAll(students); break;
            case 3: findDuplicateSurnames(students); break;
            case 4: findClassDuplicates(students); break;
            case 0: break;
            default: cout << "Неверный выбор.\n";
        }
    } while (choice != 0);

    return 0;
}
