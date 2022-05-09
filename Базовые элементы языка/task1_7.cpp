#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	double x, y, result;

	cout << "Введите два числа через пробел: ";
	cin >> x >> y; //ввод

	result = exp(sqrt(log((x * x + y * y) / (cos(x) * cos(x) + cos(x * x))))); //формула

	cout << "Ответ: " << result << endl; //вывод

    system("pause");
	return 0;
}
