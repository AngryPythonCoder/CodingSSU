#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    double a, b, c, d, e, f, det, detX, detY;

    cout << "������ ������: "; //����
    cin >> a >> b >> c;

    cout << "������ ������: ";
    cin >> d >> e >> f;

    if ((a == 0 && b == 0) && (d == 0 && e == 0))
        cout << "�� ������" << endl;

    else if (a == 0 && b == 0)
        cout << "1 ��������� - �� ������" << endl;

    else if (d == 0 && e == 0)
        cout << "2 ��������� - �� ������" << endl;

    else {
        det = (a * e - b * d); //��������� ������������ ��� ���������� ������� �������
        detX = (b * f - c * e);
        detY = (c * d - a * f);

        if (det == 0) {
            if ((detX != 0) || (detY != 0)) { //���������������� ������������ ��� x, y
                cout << "�����������" << endl;

            } else //��������������� ��� ������������
                cout << "���������" << endl;

        } else {
            double x = detX / det; //������� ������� �� �����, ���� ����� �����������
            double y = detY / det;
            cout << "������������ � ����� (" << x << ", " << y << ")" << endl;
        }
    }

    system("pause");
    return 0;
}
