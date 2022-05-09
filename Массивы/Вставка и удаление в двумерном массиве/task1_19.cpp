#include<iostream>
#include<algorithm>

using namespace std;

void arr_in(int *arr, int n) { // функция ввода массива из консоли
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

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

bool condition(int **matr, int n, int column, int x) { // проверка, что сумма столбца != X
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += matr[i][column];

    return (sum != x);
}

int task(int **matr, int n, int m, int x) {
    int current = 0;

    for (int j = 0; j < m; j++) { // перезаполнение
        if (condition(matr, n, j, x)) { // если сумма != x
            for (int i = 0; i < n; i++)
                matr[i][current] = matr[i][j]; // тогда перезаписываем
            current++;
        }
    }
    return current;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, x;

    cout << "Введите n: "; // ввод
    cin >> n;

    cout << "Введите x: "; // ввод
    cin >> x;

    int **matr = new int *[n];

    cout << endl << "Начальная матрица: " << endl;
    matrix_in(matr, n, n); // ввод матрицы
    cout << endl;

    int length = task(matr, n, n, x); // выполнение задачи, возвращает итоговую длину

    cout << "Конечная матрица: " << endl;
    matrix_out(matr, n, length); // вывод матрицы

    system("pause");
    return 0;
}
