#include<iostream>
#include<algorithm>

using namespace std;

void arr_in(int *arr, int n) { // функция ввода массива из консоли
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void matrix_in(int **matr, int n, int m) { // функция ввода матрицы
    for (int i = 0; i < n; i++) {
        matr[i] = new int[2*m]; // количество столбцов с запасом

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

bool condition(int **matr, int n, int column, int y) { //функция условия, что сумма столбца кратна Y
    int sum = 0;

    for (int i = 0; i < n; i++) // считаем сумму
        sum += matr[i][column];

    return (sum % y == 0);
}

int task(int **matr, int *arr, int n, int m, int y) {
    int inserts = 0;

    for(int i = 0; i < n; i++) //подсчёт количества дополнительных столбцов
        if (condition(matr, n, i, y))
            inserts++;

    int current = m + inserts - 1; // поддерживаем индекс для вставки

    for (int j = (m-1); j >= 0; j--) { // перезаполнение
        for (int i = 0; i < n; i++)
            matr[i][current] = matr[i][j]; // сначала перезаписываем столбец
        current--;

        if (condition(matr, n, j, y)) {   // затем, при выполненном условии
            for (int i = 0; i < m; i++)
               matr[i][current] = arr[j];  // добавляем столбец x (он окажется перед проверенным столбцом)
            current--;
        }
    }

    return m + inserts;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, y;

    cout << "Введите n: "; // ввод
    cin >> n;

    cout << "Введите y: "; // ввод
    cin >> y;

    int **matr = new int *[n];
    int *arr = new int[n];

    cout << "Столбец для вставки: "; // ввод x
    arr_in(arr, n);
    cout << endl;

    cout << "Начальная матрица: " << endl;
    matrix_in(matr, n, n); // ввод матрицы
    cout << endl;

    int length = task(matr, arr, n, n, y); // выполнение задачи, возвращает итоговую длину

    cout << "Конечная матрица: " << endl;
    matrix_out(matr, n, length); // вывод матрицы

    system("pause");
    return 0;
}
