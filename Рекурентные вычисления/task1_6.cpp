#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    double last = 2, current = 1; // первый и второй элемент
    int n;

    cout << "¬ведите n: ";
    cin >> n; // ввод натурального числа

    cout <<"1: " << last << endl; // выводим первый член

    if (n > 1)
        cout << "2: " << current << endl; // при необходимости второй

    for (int i = 2; i < n; i++) {
        last = (current / 2 + last / 3) / 3; // подсчитываем новый на основе двух последних
        swap(current, last);                 // и мен€ем местами, чтобы соблюдать пор€док

        cout << i + 1 << ": " << current << endl; // вывод
    }

    system("pause");
    return 0;
}
