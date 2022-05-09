#include<iostream>

using namespace std;

void arr_in(int *arr, int n) { // функция ввода массива из консоли
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int task(int *arr, int n, int x) { // задача
    int current = 0; // второй индекс для поддержания позиции для переноса значений

    for (int i = 0; i < n; i++) {
        if (arr[i] != x) {
            arr[current] = arr[i]; // перезаписываем элементы != x
            current++;             // обновляем индекс
        }
    }

    return current; // возвращаем новую длину
}

void arr_out(int *arr, int n) { // функция вывода массива в консоль
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, x;

    cout << "Введите n: "; // ввод
    cin >> n;

    cout << "Введите x: ";
    cin >> x;

    int *arr = new int[n];

    cout << "Массив: ";
    arr_in(arr, n); // ввод

    n = task(arr, n, x); // удаление

    cout << "Новый массив: ";
    arr_out(arr, n); // вывод

    system("pause");
    return 0;
}
