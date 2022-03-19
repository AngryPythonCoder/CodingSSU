#include <iostream>

using namespace std;

void matrix_in(int **matr, int n, int m) { // ������� ����� �������
    for (int i = 0; i < n; i++) {
        matr[i] = new int[m];

        for (int j = 0; j < m; j++)
            cin >> matr[i][j];
    }
}

void task(int **matr, int n, int m) { // ������
    double answer;
    int cnt = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i >= min(j, m-1-j) && i <= max(j, m-1-j) && (matr[i][j] % 2 == 1)) {
                answer += matr[i][j]; // ���������� � ����� ������ �������
                cnt++;             // ����������� ����������
            }

    cout << "������� ��������������: " << answer / cnt << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "������� n: "; // ����
    cin >> n;

    int **matr = new int *[n];

    matrix_in(matr, n, n); // ���� �������

    task(matr, n, n); // ���������� ������

    system("pause");
    return 0;
}
