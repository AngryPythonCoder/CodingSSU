#include <iostream>

using namespace std;

int main() {
	int n, k;
	long long current = 10; //�������� ������� ��� ������� �������

	cin >> n >> k; //����

	cout << "0.";

	for (int i = 0; i < k; i++) {
        if (current < n) // ���� ������� ������� ���
            cout << 0;   // ����� 0, ��������� ������

        else {
            cout << current / n; // ����� ���������� ����� ��������
            current %= n;        // � ������� ����� �������
        }

        current *= 10; //��� �������� �� ��������� ����� ��������� �� 10
	}

    cout << endl;

	system("pause");
	return 0;
}
