#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

	double a, b, h;

	cin >> a >> b >> h; //����

	for (double current = a; current <= b; current += h) {
        cout << "x = " << current << ": ";

		if (current == 1) cout << "�������� �� ���������������� �����" << endl; // ��������� ��� ���������� > 0 ������, ����� 1
		else if (current < 3) cout << "������ �� �������������� �����" << endl; // x - 3 >= 0, ����� x >= 3
		else if (current == 4) cout << "������� �� ����" << endl;               // ��� 4 ����������� ����������
		else cout << log((current-1)*(current-1)) / (1 - sqrt(current-3)) << endl; // �����
	}

	system("pause");
	return 0;
}
