#include <iostream>
#include <cmath>

using namespace std;

/* ��������, �������� ��� �������� � 2,
������� ��� ������ ��������� ������� �� ������������
*/

int main() {
    setlocale(LC_ALL, "RUS");

    int n = 0;
    double eps, S, a;

    cout << "������� eps: "; // ����
    cin >> eps;

    a = 1; // ��������� ��������
    S = a;

    for (n = 2; abs(a) > eps; n++) {
        a /= 2; // ������� ���������� ����� ����
        S += a; // ����� �����
    }

    cout << "�����: " << S << endl; //�����
    cout << n - 1 << " ��������" << endl;

    system("pause");
    return 0;
}
