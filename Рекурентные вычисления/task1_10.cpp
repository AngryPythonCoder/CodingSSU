#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    int n;
    double x, S, a;

    cout << "������� n: "; // ����
    cin >> n;

    cout << "������� x: ";
    cin >> x;

    a = (27 * x) / 2; // ��������� ��������
    S = a;

    for (int i = 2; i <= n; i++) {
        a *= 9 * x*x / i; // ������� ���������� ����� ����
        S += a;           // ����� �����
    }

    cout << "�����: " << S << endl; //�����

    system("pause");
    return 0;
}
