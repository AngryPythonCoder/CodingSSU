#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    double last = 2, current = 1; // ������ � ������ �������
    int n;

    cout << "������� n: ";
    cin >> n; // ���� ������������ �����

    cout <<"1: " << last << endl; // ������� ������ ����

    if (n > 1)
        cout << "2: " << current << endl; // ��� ������������� ������

    for (int i = 2; i < n; i++) {
        last = (current / 2 + last / 3) / 3; // ������������ ����� �� ������ ���� ���������
        swap(current, last);                 // � ������ �������, ����� ��������� �������

        cout << i + 1 << ": " << current << endl; // �����
    }

    system("pause");
    return 0;
}
