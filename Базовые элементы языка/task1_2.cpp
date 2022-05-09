#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	double x, y, result;

	cout << "Введите два числа через пробел: ";
	cin >> x >> y; //ввод

	result = (x * y) / 5 + sqrt((exp(x-1) + exp(y-1)) / (cos(x+2*y) * cos(x+2*y))); //формула

	cout << "Ответ: " << result << endl; //вывод

    system("pause");
	return 0;
}
