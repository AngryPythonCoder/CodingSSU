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

    int n, x;
    bool flag = true;
    int *arr = new int [n];
    srand((unsigned)time(NULL));

    cout << "Введите n: "; // ввод
    cin >> n;

    cout << "Введите x: ";
    cin >> x;

    for (int i = 0; i < n; i++) // генерация значений в массиве
        arr[i] = rand() % 100;

    cout << "Массив: ";
    arr_out(arr, n); // вывод массива

    for (int i = 0; i < n; i++)
        if (arr[i] % x) { // возвращает true, когда остаток не нулевой, т.е. когда не кратно x
            cout << i << " ";
            flag = false;
        }


    if (flag) cout << "Таких элементов нет"; // если отсутствуют необходимые элементы

    system("pause");
    return 0;
}
