#include <iostream>

using namespace std;

void arr_in(int *arr, int n) { // функция ввода массива из консоли
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void calc_der(int *der, int *arr, int n) { // подсчёт производной
    for (int i = 0; i < n; i++)
        der[i] = arr[i+1] * (i + 1); // домножаем коэффициент по формуле (x^n)' = nx^(n-1)
}

void task(int *ans, int *der, int *arr, int n) { // задача
    fill(ans, ans + 2*n, 0);

    for (int i = 0; i < (n+1); i++)
    for (int j = 0; j < n; j++) {
            ans[i+j] += arr[i] * der[j]; // считаем произведение
    }
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
    int *der = new int[n];
    int *ans = new int[2*n];

    cout << "Коэффициенты многочлена: ";
    arr_in(arr, n+1); //ввод

    calc_der(der, arr, n); //подсчёт производной

    task(ans, der, arr, n); //подсчёт произведения

    cout << "Произведение многочлена на его производную: ";
    arr_out(ans, 2*n); //вывод

    system("pause");
    return 0;
}
