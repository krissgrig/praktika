#include <iostream>
#include <iomanip> // для форматирования таблицы
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int months_in_year = 12;
    const int litter_interval = 4;
    const int litter_count = 5;

    cout << "Пары\tПриплод за год\n";
    cout << "-----------------------\n";

    for (int pairs = 1; pairs <= 20; pairs++) {
        int litters_per_year = months_in_year / litter_interval;
        int total_offspring = pairs * litter_count * litters_per_year;

        cout << setw(4) << pairs << "\t" << total_offspring << "\n";
    }

    return 0;
}
