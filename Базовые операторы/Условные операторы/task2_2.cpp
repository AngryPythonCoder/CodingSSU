#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    int a, x;
    cin >> a >> x; //ввод

    if (a > 99 && a < 1000 && x > 0 && x < 10) {
        int third = a % 10; //цифры числа
        int second = (a / 10) % 10;
        int first = (a / 100) % 10;

        if (first > x && second > x) {
            if (third > x) //если все цифры > x
                a -= 100;
            else           //если только первая и вторая
                a += 100;

        } else if (second < x && third < x) {
            if (first < x) //если все цифры < x
                a -= 50;
            else           //если только вторая и третья
                a += 50;

        } else
            a += 10;

        cout << a << endl; //вывод

    } else
        cout << "Некорректный ввод" << endl; //некорректный ввод

    system("pause");
    return 0;
}
