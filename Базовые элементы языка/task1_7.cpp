#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	double x, y, result;

	cout << "������� ��� ����� ����� ������: ";
	cin >> x >> y; //����

	result = exp(sqrt(log((x * x + y * y) / (cos(x) * cos(x) + cos(x * x))))); //�������

	cout << "�����: " << result << endl; //�����

    system("pause");
	return 0;
}
