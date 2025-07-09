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
    cout << "������� ���: ";
    cin >> s.name;
    cout << "������� �������: ";
    cin >> s.surname;
    cout << "������� ����� ������ (1-11): ";
    cin >> s.grade;
    cout << "������� ����� ������: ";
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
                cout << "������������: ";
                printStudent(students[i]);
                printStudent(students[j]);
                found = true;
            }
        }
    }
    if (!found)
        cout << "������������� � ����� ���.\n";
}

void findClassDuplicates(const vector<Student>& students) {
    bool found = false;
    for (size_t i = 0; i < students.size(); ++i) {
        for (size_t j = i + 1; j < students.size(); ++j) {
            if (students[i].surname == students[j].surname &&
                students[i].grade == students[j].grade &&
                students[i].letter == students[j].letter) {
                cout << "������������ � ����� ������: ";
                printStudent(students[i]);
                printStudent(students[j]);
                found = true;
            }
        }
    }
    if (!found)
        cout << "� ������� ������������� ���.\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Student> students;
    int choice;

    do {
        cout << "\n����:\n";
        cout << "1. �������� �������\n";
        cout << "2. ������� ���� ��������\n";
        cout << "3. ����� ������������� � �����\n";
        cout << "4. ����� ������������� � ����� ������\n";
        cout << "0. �����\n";
        cout << "�����: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: printAll(students); break;
            case 3: findDuplicateSurnames(students); break;
            case 4: findClassDuplicates(students); break;
            case 0: break;
            default: cout << "�������� �����.\n";
        }
    } while (choice != 0);

    return 0;
}
