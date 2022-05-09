#include<iostream>
#include<algorithm>

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

int task(int **matr, int n, int m) { // задача
    int current = 0; // индекс позиции для заполнения

    for (int i = 0; i < n; i++) // перезаполнение
        if (*min_element(matr[i], matr[i]+m) <= 0) // если в строчке есть неположительные элементы
            matr[current++] = matr[i];             // она перезаписывается

    return current;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "Введите n: "; // ввод
    cin >> n;

    int **matr = new int *[n];

    cout << endl << "Начальная матрица: " << endl;
    matrix_in(matr, n, n); // ввод матрицы
    cout << endl;

    int length = task(matr, n, n); // выполнение задачи, возвращает итоговую длину

    cout << "Конечная матрица: " << endl;
    matrix_out(matr, length, n); // вывод матрицы

    system("pause");
    return 0;
}
