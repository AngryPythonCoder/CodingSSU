#include <iostream>
#include <cmath>

using namespace std;

/* Очевидно, заданный ряд сходится к 2,
поэтому нет смысла добавлять условие на расходимость
*/

int main() {
    setlocale(LC_ALL, "RUS");

    int n = 0;
    double eps, S, a;

    cout << "Введите eps: "; // ввод
    cin >> eps;

    a = 1; // начальные значения
    S = a;

    for (n = 2; abs(a) > eps; n++) {
        a /= 2; // подсчёт следующего члена ряда
        S += a; // новая сумма
    }

    cout << "Сумма: " << S << endl; //вывод
    cout << n - 1 << " итераций" << endl;

    system("pause");
    return 0;
}
