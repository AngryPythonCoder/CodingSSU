#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int A, B;
int func(int sum, int x) { // функция суммирования с условием
    if (!((A <= x) && (x <= B)))
        sum += x;

    return sum;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;
    vector<int> v;

    cout << "Введите n, a, b: ";
    cin >> n >> A >> B; // ввод
    v.resize(n);

    cout << "Последовательность: ";
    for(int i = 0; i < n; i++) // заполнение
        cin >> v[i];

    cout << "Сумма элементов, не попадающих в интервал: " << accumulate(v.begin(), v.end(), 0, func) << endl; // вывод

    return 0;
}
