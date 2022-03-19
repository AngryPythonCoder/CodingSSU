#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    double x;

    cin >> x; //����

    double current = x * x - 9;

    if (current == 0) { //���� ����������� = 0
        cout << "������� �� ����" << endl;

    } else {
        current = (x - 5) / current;

        if (current < 0) { //���� ������ �� ��������������
            cout << "������ �� �������������� �����" << endl;

        } else {
            current = sqrt(current);

            if (x == -1) { //(x+1)^2 > 0 ��� ���� x ����� -1
                cout << "�������� ���������������� �����" << endl;

            } else {
                cout << current + log((x+1)*(x+1)) << endl;
            }
        }
    }

    system("pause");
    return 0;
}
