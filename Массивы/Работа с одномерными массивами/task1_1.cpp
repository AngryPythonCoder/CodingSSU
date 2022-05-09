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

    int n, left, right, answer = 0;
    int *arr = new int [n];
    srand((unsigned)time(NULL));

    cout << "Введите n: "; // ввод
    cin >> n;

    cout << "Введите левую и правую границу через пробел: ";
    cin >> left >> right;

    for (int i = 0; i < n; i++) // генерация значений в массиве
        arr[i] = rand() % 15;

    cout << "Массив: ";
    arr_out(arr, n); // вывод массива

    for (int i = 0; i < n; i++)
        answer += ((arr[i] % 2 == 0) && (arr[i] >= left) && (arr[i] <= right)) ? arr[i]: 0; // подсчёт суммы чётных элементов из интервала

    if (answer == 0) cout << "Таких элементов нет" << endl; // вывод
    else cout << "Сумма: " <<  answer << endl;

    system("pause");
    return 0;
}
