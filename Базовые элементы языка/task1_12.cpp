#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	int number, a, b, c, result;

	cout << "Введите трёхзначное число: ";
	cin >> number; //ввод

    a = (number / 100) % 10; //цифры исходного числа от первой до последней
    b = (number / 10) % 10;
	c = number % 10;

	result = (25 % a) * 100 + (25 % b) * 10 + (25 % c);	//вычисление Y

	cout << "Ответ: " << result << endl; //вывод

	system("pause");
	return 0;
}
