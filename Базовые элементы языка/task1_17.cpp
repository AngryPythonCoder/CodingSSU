#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	int number, a, b, c, result;

	cout << "������� ���������� �����: ";
	cin >> number; //����

    a = (number / 100) % 10; //����� ��������� ����� �� ������ �� ���������
    b = (number / 10) % 10;
	c = number % 10;

	result = ((a + b + c) % 10) * 100 + ((a * b * c) / 100) * 10 + ((b + c) % a);	//���������� Y

	cout << "�����: " << result << endl; //�����

	system("pause");
	return 0;
}
