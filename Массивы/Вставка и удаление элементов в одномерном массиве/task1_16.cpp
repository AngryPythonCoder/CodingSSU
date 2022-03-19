#include<iostream>
#include<algorithm>

using namespace std;

void arr_in(int *arr, int n) { // функция ввода массива из консоли
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int task(int *arr, int n, int curr, int x, int y) { // используем функцию из 11-ого задания
    for (int i = (n-1); i >= 0; i--) {
        arr[curr--] = arr[i]; // но сначала перезаписываем i-ый элемент

        if (arr[i] == x)      // и только затем, если элемент = x
            arr[curr--] = y;  // то записываем y перед перезаписанными элементами
    }

    return curr; // возвращаем новую длину
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

    int *arr = new int[2*n]; // массив объявляем с запасом, больше 2n быть не может

    cout << "Массив: ";
    arr_in(arr, n); // ввод

    int maximum = *max_element(arr, arr+n);
    int len = n + count(arr, arr+n, maximum); // итоговая длина
    int curr = len - 1;

    task(arr, n, curr, maximum, x); // преобразуем массив

    cout << "Новый массив: ";
    arr_out(arr, len); // вывод

    system("pause");
    return 0;
}
