#include<iostream>
#include<algorithm>

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

int task(int **matr, int n, int m) { // ������
    int current = 0; // ������ ������� ��� ����������

    for (int i = 0; i < n; i++) // ��������������
        if (*min_element(matr[i], matr[i]+m) <= 0) // ���� � ������� ���� ��������������� ��������
            matr[current++] = matr[i];             // ��� ����������������

    return current;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "������� n: "; // ����
    cin >> n;

    int **matr = new int *[n];

    cout << endl << "��������� �������: " << endl;
    matrix_in(matr, n, n); // ���� �������
    cout << endl;

    int length = task(matr, n, n); // ���������� ������, ���������� �������� �����

    cout << "�������� �������: " << endl;
    matrix_out(matr, length, n); // ����� �������

    system("pause");
    return 0;
}
