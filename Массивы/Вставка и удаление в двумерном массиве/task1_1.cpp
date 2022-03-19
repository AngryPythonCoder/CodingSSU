#include<iostream>
#include<algorithm>

using namespace std;

void arr_in(int *arr, int n) { // ������� ����� ������� �� �������
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void matrix_in(int **matr, int n, int m) { // ������� ����� �������
    for (int i = 0; i < n; i++) {
        matr[i] = new int[m];

        for (int j = 0; j < m; j++)
            cin >> matr[i][j];
    }
}

void matrix_out(int **matr, int n, int m) { // ������� ������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matr[i][j] << " ";

        cout << endl;
    }
}

int task(int **matr, int *arr, int n, int m) {
    int inserts = 0;

    for(int i = 0; i < n; i++) // ������� ���������� �������������� �����
        if (*min_element(matr[i],matr[i]+m) > 0) // ���� ��� �������� ������������, �� ����������� > 0
            inserts++;

    int current = n + inserts - 1; // ������������ ������ ��� �������

    for (int i = (n-1); i >= 0; i--) { // ��������������
        if (*min_element(matr[i], matr[i]+m) > 0) // ��� ���������� �������
            matr[current--] = arr;                // ������� ��������� x

        matr[current--] = matr[i];                // ����� �������������� ������� (��� ����� ����� x)
    }

    return n + inserts;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "������� n: "; // ����
    cin >> n;

    int **matr = new int *[2*n]; // ���������� ����� � �������
    int *arr = new int[n];

    cout << "������ ��� �������: "; // ���� x
    arr_in(arr, n);
    cout << endl;

    cout << "��������� �������: " << endl;
    matrix_in(matr, n, n); // ���� �������
    cout << endl;

    int length = task(matr, arr, n, n); // ���������� ������, ���������� �������� �����

    cout << "�������� �������: " << endl;
    matrix_out(matr, length, n); // ����� �������

    system("pause");
    return 0;
}
