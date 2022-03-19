#include <iostream>
#include <complex>

using namespace std;

void matrix_out(int **matr, int n, int m) { // ������� ������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matr[i][j] << " ";

        cout << endl;
    }
}

void task(int **matr, int n, int m) { // ������
    for (int i = 0; i < n; i++) {
        matr[i] = new int[m];

        for (int j = 0; j < m; j++)
            matr[i][j] = ((m - 1) - j) * n + (((m-1-j) % 2) ? n - 1 - i : i); // ��������� �������� �������
    }
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "������� n: "; // ����
    cin >> n;

    int **matr = new int *[n];

    task(matr, n, n); // ���������� ������

    matrix_out(matr, n, n); // ����� �������

    system("pause");
    return 0;
}
