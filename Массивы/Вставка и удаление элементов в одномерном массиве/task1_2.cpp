#include<iostream>

using namespace std;

void arr_in(int *arr, int n) { // ������� ����� ������� �� �������
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int task(int *arr, int n, int x) { // ������
    int current = 0; // ������ ������ ��� ����������� ������� ��� �������� ��������

    for (int i = 0; i < n; i++) {
        if (arr[i] != x) {
            arr[current] = arr[i]; // �������������� �������� != x
            current++;             // ��������� ������
        }
    }

    return current; // ���������� ����� �����
}

void arr_out(int *arr, int n) { // ������� ������ ������� � �������
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, x;

    cout << "������� n: "; // ����
    cin >> n;

    cout << "������� x: ";
    cin >> x;

    int *arr = new int[n];

    cout << "������: ";
    arr_in(arr, n); // ����

    n = task(arr, n, x); // ��������

    cout << "����� ������: ";
    arr_out(arr, n); // �����

    system("pause");
    return 0;
}
