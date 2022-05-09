#include <iostream>
#include <ctime>

using namespace std;

void arr_out(int *arr, int length) { // функция вывода массива в консоль
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int b = -1, a = 21; // базовые значения максимума, минимума
    int *maximum = &b, *minimum = &a; // указатели на максимум, минимум

    int n;
    float average = 0;
    int *arr = new int [n];
    srand((unsigned)time(NULL));

    cout << "Введите n: "; // ввод
    cin >> n;

    for (int i = 0; i < n; i++) // генерация значений в массиве
        arr[i] = rand() % 21;

    cout << "Массив: ";
    arr_out(arr, n); // вывод массива

    for (int i = 0; i < n; i++) {
        if (arr[i] < *minimum) // ищем первый минимум
            minimum = &arr[i];

        if (arr[i] >= *maximum) // ищем последниий максимум
            maximum = &arr[i];
    }

    if (maximum < minimum)
        cout << "MAX перед MIN" << endl;

    else if (maximum == (minimum + 1))
        cout << "0 элементов между MAX и MIN" << endl;

    else {
        for (int *current = minimum+1; current < maximum; current++) // с помощью итератора проходим по элементам в диапазоне
            average += *current;

        average /= (maximum - minimum) - 1; // считаем среднее арифметическое

        cout << "Среднее арифметическое: " << average; // вывод
    }

    system("pause");
    return 0;
}
