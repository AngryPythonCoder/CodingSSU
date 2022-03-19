#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	int number, a, b, c, result;

	cout << "¬ведите трЄхзначное число: ";
	cin >> number; //ввод

    a = (number / 100) % 10; //цифры исходного числа от первой до последней
    b = (number / 10) % 10;
	c = number % 10;

	result = ((a + b + c) % 10) * 100 + ((a * b * c) / 100) * 10 + ((b + c) % a);	//вычисление Y

	cout << "ќтвет: " << result << endl; //вывод

	system("pause");
	return 0;
}
