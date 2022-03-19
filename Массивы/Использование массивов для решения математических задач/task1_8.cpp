#include <iostream>

using namespace std;

void arr_in(int *arr, int n) { // ������� ����� ������� �� �������
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void calc_der(int *der, int *arr, int n) { // ������� �����������
    for (int i = 0; i < n; i++)
        der[i] = arr[i+1] * (i + 1); // ��������� ����������� �� ������� (x^n)' = nx^(n-1)
}

void task(int *ans, int *der, int *arr, int n) { // ������
    fill(ans, ans + 2*n, 0);

    for (int i = 0; i < (n+1); i++)
    for (int j = 0; j < n; j++) {
            ans[i+j] += arr[i] * der[j]; // ������� ������������
    }
}

void arr_out(int *arr, int n) { // ������� ������ ������� � �������
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "������� n: "; // ����
    cin >> n;

    int *arr = new int[n+1];
    int *der = new int[n];
    int *ans = new int[2*n];

    cout << "������������ ����������: ";
    arr_in(arr, n+1); //����

    calc_der(der, arr, n); //������� �����������

    task(ans, der, arr, n); //������� ������������

    cout << "������������ ���������� �� ��� �����������: ";
    arr_out(ans, 2*n); //�����

    system("pause");
    return 0;
}
