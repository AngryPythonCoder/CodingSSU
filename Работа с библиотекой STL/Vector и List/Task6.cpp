#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int X;
int func(int sum, int x) { // функция суммирования с условием
    if (x % X == 0)
        sum += x;

    return sum;
}

bool even(int x) { // проверка чётности
    return (x % 2 == 0);
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, a, b, maximum;
    vector<int> v;

    cout << "Введите n, X: ";
    cin >> n >> X; // ввод
    v.resize(n);

    cout << "Последовательность: ";
    for(int i = 0; i < n; i++) // заполнение
        cin >> v[i];

    cout << "Сумма элементов, кратных " << X << ": " << accumulate(v.begin(), v.end(), 0, func) << endl; // вывод
    cout << "Минимальный элемент: " << *min_element(v.begin(), v.end()) << endl;

    maximum = *max_element(v.begin(), v.end()); // нахождение максимума
    replace_if(v.begin(), v.end(), even, maximum); // и замена чётных элементов на максимум

    cout << "Итоговая последовательность: ";
    for(int i = 0; i < n; i++) // вывод
        cout << v[i] << " ";

    return 0;
}
