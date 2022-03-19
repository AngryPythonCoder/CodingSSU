#include<iostream>
#include<algorithm>

using namespace std;

void arr_in(int *arr, int n) { // ������� ����� ������� �� �������
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void matrix_in(int **matr, int n, int m) { // ������� ����� �������
    for (int i = 0; i < n; i++) {
        matr[i] = new int[2*m]; // ���������� �������� � �������

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

bool condition(int **matr, int n, int column, int y) { //������� �������, ��� ����� ������� ������ Y
    int sum = 0;

    for (int i = 0; i < n; i++) // ������� �����
        sum += matr[i][column];

    return (sum % y == 0);
}

int task(int **matr, int *arr, int n, int m, int y) {
    int inserts = 0;

    for(int i = 0; i < n; i++) //������� ���������� �������������� ��������
        if (condition(matr, n, i, y))
            inserts++;

    int current = m + inserts - 1; // ������������ ������ ��� �������

    for (int j = (m-1); j >= 0; j--) { // ��������������
        for (int i = 0; i < n; i++)
            matr[i][current] = matr[i][j]; // ������� �������������� �������
        current--;

        if (condition(matr, n, j, y)) {   // �����, ��� ����������� �������
            for (int i = 0; i < m; i++)
               matr[i][current] = arr[j];  // ��������� ������� x (�� �������� ����� ����������� ��������)
            current--;
        }
    }

    return m + inserts;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, y;

    cout << "������� n: "; // ����
    cin >> n;

    cout << "������� y: "; // ����
    cin >> y;

    int **matr = new int *[n];
    int *arr = new int[n];

    cout << "������� ��� �������: "; // ���� x
    arr_in(arr, n);
    cout << endl;

    cout << "��������� �������: " << endl;
    matrix_in(matr, n, n); // ���� �������
    cout << endl;

    int length = task(matr, arr, n, n, y); // ���������� ������, ���������� �������� �����

    cout << "�������� �������: " << endl;
    matrix_out(matr, n, length); // ����� �������

    system("pause");
    return 0;
}
