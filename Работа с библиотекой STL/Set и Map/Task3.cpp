#include <iostream>
#include <set>

using namespace std;

set<int> digit, // множеств цифр в наборе
    two_digit = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, // множество цифр, не встречающихся в двузначных числах
    three_digit = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};    // множество цифр, не встречающихся в трёхзначных числах

void update_lists(int &x) { // функция обновления множеств
    if ((x >= 10) && (x < 100)) { // ветка для двузначного числа
        int a = x / 10;
        int b = x % 10;
        
        two_digit.erase(a);
        two_digit.erase(b);
    }

    if ((x >= 100) && (x < 1000)) { // для трёхзначного
        int a = x / 100;
        int b = (x / 10) % 10;
        int c = x % 10;
        
        three_digit.erase(a);
        three_digit.erase(b);
        three_digit.erase(c);
    }

    while (x != 0) { // запись цифр
        digit.insert(x % 10);
        x /= 10;
    }
}

int main() {
    int n, current;

    cout << "Input n: "; // ввод
    cin >> n;

    cout << "Input a sequence of numbers:" << endl;
    for (int i = 0; i < n; i++) { // перебор чисел в последовательности
        cin >> current;
        update_lists(current);
    }

    for (set<int>::iterator it = digit.begin(); it != digit.end(); it++)
        if ((two_digit.find(*it) != two_digit.end()) && (three_digit.find(*it) != three_digit.end())) // вывод подходящих
            cout << *it << " ";

    return 0;
}