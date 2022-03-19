#include <iostream>
#include <ctime>

using namespace std;

void arr_out(int *arr, int length) { // ������� ������ ������� � �������
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, x;
    bool flag = true;
    int *arr = new int [n];
    srand((unsigned)time(NULL));

    cout << "������� n: "; // ����
    cin >> n;

    cout << "������� x: ";
    cin >> x;

    for (int i = 0; i < n; i++) // ��������� �������� � �������
        arr[i] = rand() % 100;

    cout << "������: ";
    arr_out(arr, n); // ����� �������

    for (int i = 0; i < n; i++)
        if (arr[i] % x) { // ���������� true, ����� ������� �� �������, �.�. ����� �� ������ x
            cout << i << " ";
            flag = false;
        }


    if (flag) cout << "����� ��������� ���"; // ���� ����������� ����������� ��������

    system("pause");
    return 0;
}
