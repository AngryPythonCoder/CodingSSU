#include<iostream>
#include<algorithm>

using namespace std;

void arr_in(int *arr, int n) { // ������� ����� ������� �� �������
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int task(int *arr, int n, int curr, int x, int y) { // ���������� ������� �� 11-��� �������
    for (int i = (n-1); i >= 0; i--) {
        arr[curr--] = arr[i]; // �� ������� �������������� i-�� �������

        if (arr[i] == x)      // � ������ �����, ���� ������� = x
            arr[curr--] = y;  // �� ���������� y ����� ��������������� ����������
    }

    return curr; // ���������� ����� �����
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

    int *arr = new int[2*n]; // ������ ��������� � �������, ������ 2n ���� �� �����

    cout << "������: ";
    arr_in(arr, n); // ����

    int maximum = *max_element(arr, arr+n);
    int len = n + count(arr, arr+n, maximum); // �������� �����
    int curr = len - 1;

    task(arr, n, curr, maximum, x); // ����������� ������

    cout << "����� ������: ";
    arr_out(arr, len); // �����

    system("pause");
    return 0;
}
