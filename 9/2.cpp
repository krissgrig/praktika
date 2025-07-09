#include <iostream>
#include <fstream>
#include <stack>
#include <string>

std::string removeBrackets(const std::string& input) {
    std::string result;
    std::stack<char> brackets;
    for (char ch : input) {
        if (ch == '(') {
            brackets.push(ch);
        } else if (ch == ')') {
            if (!brackets.empty()) {
                brackets.pop();
            }
        } else {
            if (brackets.empty()) {
                result += ch;
            }
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream inputFile("9/F1.txt");
    std::ofstream outputFile("9/F2.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Ошибка открытия файла.\n";
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::string processed = removeBrackets(line);
        outputFile << processed << std::endl;
    }
    inputFile.close();
    outputFile.close();

    std::cout << "Обработка завершена. Результат записан в F2.txt\n";
    return 0;
}
