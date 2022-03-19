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

    int n;
    int *arr = new int [n];
    srand((unsigned)time(NULL));

    cout << "Введите n: "; // ввод
    cin >> n;

    for (int i = 0; i < n; i++) // генерация значений в массиве
        arr[i] = rand() % 10;

    cout << "Начальный массив: ";
    arr_out(arr, n); // вывод массива

    swap(arr[n/2], arr[(1-n%2)*(n/2-1)]); // n / 2 - всегда средний, а второй индекс = 0 при нечётном n
                                          // и второму среднем элементу при чётном
    cout << "Конечный массив: ";
    arr_out(arr, n); // вывод массива

    system("pause");
    return 0;
}
