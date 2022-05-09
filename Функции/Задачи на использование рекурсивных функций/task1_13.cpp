#include<iostream>

using namespace std;

int recursion(int x) {
    if (x != 0) {
        recursion(x >> 1); // сначала вызов рекурсии от остальных разрядов

        cout << (x & 1); //далее вывод соответствующего остатка, т.к. первый остаток - последняя цифра
    }
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "Введите n: "; // ввод
    cin >> n;

    cout << "Двоичное представление: ";

    if (n == 0) //костыль для нуля
        cout << 0;

    else {
        if (n < 0) // костыль для отрицательных
            cout << '-';

        recursion(abs(n)); // вызов рекурсии
    }

    cout << endl;

    system("pause");
    return 0;
}
