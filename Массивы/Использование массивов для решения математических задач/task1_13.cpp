#include <iostream>
#include <iomanip>
#include <numeric>

using namespace std;

void line_out(int *arr, int n) { // функци€ вывода строчки треугольника в консоль
    for (int i = 0; i < n; i++)
        cout << setw(5) << arr[i+1] << " ";

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");
    cout << setiosflags(ios::left);

    int n, S, len;

    cout << "¬ведите n: "; // ввод
    cin >> n;
    len = max(10, n);

    int *arr = new int[len+2];     //два массива дл€ генерации новой строки треугольника на основе старой
    int *new_arr = new int[len+2];

    fill(arr, arr + (len+2), 0);
    fill(new_arr, new_arr + (len+2), 0);

    new_arr[1] = 1;
    cout << endl;
    line_out(new_arr, 1); // вывод нулевой строки

    if (n == 0) // костыль дл€ нул€
        S = 1;

    for (int i = 1; i <= len; i++) {
        swap(arr, new_arr);

        for (int j = 1; j <= (i+1); j++)
            new_arr[j] = arr[j-1] + arr[j]; // подсчЄт новой строки

        if (i == n)
            S = accumulate(new_arr, new_arr + (n+2), 0); // подсчЄт 2^k

        line_out(new_arr, i+1); // вывод строки
    }

    cout << endl << "2^" << n << " = " << S << endl; // вывод 2^k

    return 0;
}
