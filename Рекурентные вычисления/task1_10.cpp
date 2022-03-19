#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    int n;
    double x, S, a;

    cout << "Введите n: "; // ввод
    cin >> n;

    cout << "Введите x: ";
    cin >> x;

    a = (27 * x) / 2; // начальные значения
    S = a;

    for (int i = 2; i <= n; i++) {
        a *= 9 * x*x / i; // подсчёт следующего члена ряда
        S += a;           // новая сумма
    }

    cout << "Сумма: " << S << endl; //вывод

    system("pause");
    return 0;
}
