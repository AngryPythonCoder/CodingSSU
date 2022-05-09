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

int task(int **matr, int *arr, int n, int m) {
    int inserts = 0;

    for(int i = 0; i < n; i++) // подсчёт количества дополнительных строк
        if (*min_element(matr[i],matr[i]+m) > 0) // если все элементы положительны, то минимальный > 0
            inserts++;

    int current = n + inserts - 1; // поддерживаем индекс для вставки

    for (int i = (n-1); i >= 0; i--) { // перезаполнение
        if (*min_element(matr[i], matr[i]+m) > 0) // при выполнения условия
            matr[current--] = arr;                // сначала добавляем x

        matr[current--] = matr[i];                // затем перезаписываем строчку (она будет перед x)
    }

    return n + inserts;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "Введите n: "; // ввод
    cin >> n;

    int **matr = new int *[2*n]; // количество строк с запасом
    int *arr = new int[n];

    cout << "Строка для вставки: "; // ввод x
    arr_in(arr, n);
    cout << endl;

    cout << "Начальная матрица: " << endl;
    matrix_in(matr, n, n); // ввод матрицы
    cout << endl;

    int length = task(matr, arr, n, n); // выполнение задачи, возвращает итоговую длину

    cout << "Конечная матрица: " << endl;
    matrix_out(matr, length, n); // вывод матрицы

    system("pause");
    return 0;
}
