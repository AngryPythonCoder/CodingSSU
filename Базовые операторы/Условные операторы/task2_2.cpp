#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    int a, x;
    cin >> a >> x; //����

    if (a > 99 && a < 1000 && x > 0 && x < 10) {
        int third = a % 10; //����� �����
        int second = (a / 10) % 10;
        int first = (a / 100) % 10;

        if (first > x && second > x) {
            if (third > x) //���� ��� ����� > x
                a -= 100;
            else           //���� ������ ������ � ������
                a += 100;

        } else if (second < x && third < x) {
            if (first < x) //���� ��� ����� < x
                a -= 50;
            else           //���� ������ ������ � ������
                a += 50;

        } else
            a += 10;

        cout << a << endl; //�����

    } else
        cout << "������������ ����" << endl; //������������ ����

    system("pause");
    return 0;
}
