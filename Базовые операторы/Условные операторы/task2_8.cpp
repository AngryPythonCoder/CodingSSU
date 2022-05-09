#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    double x;

    cin >> x; //ввод

    double current = x * x - 9;

    if (current == 0) { //если знаменатель = 0
        cout << "Деление на ноль" << endl;

    } else {
        current = (x - 5) / current;

        if (current < 0) { //если корень из отрицательного
            cout << "Корень из отрицательного числа" << endl;

        } else {
            current = sqrt(current);

            if (x == -1) { //(x+1)^2 > 0 при всех x кроме -1
                cout << "Логарифм неположительного числа" << endl;

            } else {
                cout << current + log((x+1)*(x+1)) << endl;
            }
        }
    }

    system("pause");
    return 0;
}
