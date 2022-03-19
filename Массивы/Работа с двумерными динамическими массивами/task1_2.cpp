#include <iostream>

using namespace std;

void matrix_in(int **matr, int n, int m) { // функция ввода матрицы
    for (int i = 0; i < n; i++) {
        matr[i] = new int[m];

        for (int j = 0; j < m; j++)
            cin >> matr[i][j];
    }
}

void matrix_out(int **matr, int n, int m) { // функция вывода
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matr[i][j] << " ";

        cout << endl;
    }
}

void task(int **matr, int n, int m) { // задача
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (m / 2); j++)
            swap(matr[i][2*j], matr[i][2*j+1]); // меняем местами элементы из соответствующих столбцов
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "Введите n: "; // ввод
    cin >> n;

    int **matr = new int *[n];

    matrix_in(matr, n, n); // ввод матрицы

    task(matr, n, n); // выполнение задачи

    cout << endl;

    matrix_out(matr, n, n); // вывод матрицы

    system("pause");
    return 0;
}
