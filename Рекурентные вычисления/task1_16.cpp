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

    a = 2 * x; // ��������� ��������
    S = a;

    for (int i = 2; i <= n; i++) {
        a *= -x*x * (2*i - 1) * i; // ������� ���������� ����� ����
        S += a;                    // ����� �����
    }

    cout << "�����: " << S << endl; //�����

    system("pause");
    return 0;
}
