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

	result = (25 % a) * 100 + (25 % b) * 10 + (25 % c);	//���������� Y

	cout << "�����: " << result << endl; //�����

	system("pause");
	return 0;
}
