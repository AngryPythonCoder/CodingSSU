#include <iostream>

using namespace std;

void arr_in(int *arr, int n) { // функция ввода массива из консоли
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void task(int *double_der, int *arr, int n) { // задача
    for (int i = 0; i < (n-1); i++)
        double_der[i] = arr[i+2] * (i + 2) * (i + 1); // домножаем коэффициент дважды по формуле (x^n)' = nx^(n-1)
}

void arr_out(int *arr, int n) { // функция вывода массива в консоль
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "Введите n: "; // ввод
    cin >> n;

    int *arr = new int[n+1];
    int *double_der = new int[n-1];

    cout << "Коэффициенты многочлена: ";
    arr_in(arr, n+1); //ввод

    task(double_der, arr, n); //подсчёт двойной производной

    cout << "Вторая производная: ";
    arr_out(double_der, n-1); //вывод

    system("pause");
    return 0;
}
