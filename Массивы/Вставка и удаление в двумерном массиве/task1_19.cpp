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

bool condition(int **matr, int n, int column, int x) { // ��������, ��� ����� ������� != X
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += matr[i][column];

    return (sum != x);
}

int task(int **matr, int n, int m, int x) {
    int current = 0;

    for (int j = 0; j < m; j++) { // ��������������
        if (condition(matr, n, j, x)) { // ���� ����� != x
            for (int i = 0; i < n; i++)
                matr[i][current] = matr[i][j]; // ����� ��������������
            current++;
        }
    }
    return current;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, x;

    cout << "������� n: "; // ����
    cin >> n;

    cout << "������� x: "; // ����
    cin >> x;

    int **matr = new int *[n];

    cout << endl << "��������� �������: " << endl;
    matrix_in(matr, n, n); // ���� �������
    cout << endl;

    int length = task(matr, n, n, x); // ���������� ������, ���������� �������� �����

    cout << "�������� �������: " << endl;
    matrix_out(matr, n, length); // ����� �������

    system("pause");
    return 0;
}
