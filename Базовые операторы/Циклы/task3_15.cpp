#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

	double a, b, h;

	cin >> a >> b >> h; //ввод

	for (double current = a; current <= b; current += h) {
        cout << "x = " << current << ": ";

		if (current == 1) cout << "Логарифм из неположительного числа" << endl; // выражение под логарифмом > 0 всегда, кроме 1
		else if (current < 3) cout << "Корень из отрицательного числа" << endl; // x - 3 >= 0, когда x >= 3
		else if (current == 4) cout << "Деление на ноль" << endl;               // при 4 знаменатель обнуляется
		else cout << log((current-1)*(current-1)) / (1 - sqrt(current-3)) << endl; // вывод
	}

	system("pause");
	return 0;
}
