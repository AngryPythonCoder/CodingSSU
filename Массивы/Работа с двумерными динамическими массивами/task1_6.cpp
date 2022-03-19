#include <iostream>
#include <limits.h>

using namespace std;

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

void task(int **matr, int n, int m) { // ������
    int minimum = INT_MAX, maximum = 0, row_min, row_max;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matr[i][j] < minimum) { // ���������� ��������
                minimum = matr[i][j];
                row_min = i;
            }

            if (matr[i][j] > maximum) { // ���������� ���������
                maximum = matr[i][j];
                row_max = i;
            }
        }
    }

    swap(matr[row_min], matr[row_max]);
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "������� n: "; // ����
    cin >> n;

    int **matr = new int *[n];

    matrix_in(matr, n, n); // ���� �������

    task(matr, n, n); // ���������� ������

    cout << endl;

    matrix_out(matr, n, n); // ����� �������

    system("pause");
    return 0;
}
