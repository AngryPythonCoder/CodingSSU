#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int X;
bool pred1(int x) { // условие чётности и кратности X
    return ((x % 2 == 0) && (x % X == 0));
}

int Y;
bool pred2(int x) { // проверка равенства заданой константе
    return (x == Y);
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, m, curr_elem, new_elem, maximum;
    list<int> lst1, lst2;

    cout << "Введите длины последовательностей, X и вставляемый элемент: ";
    cin >> n >> m >> X >> new_elem; // ввод

    cout << "Первая последовательность: ";
    for(int i = 0; i < n; i++) { // заполнение
        cin >> curr_elem;
        lst1.push_back(curr_elem);
    }

    cout << "Вторая последовательность: ";
    for(int i = 0; i < m; i++) { // заполнение
        cin >> curr_elem;
        lst2.push_back(curr_elem);
    }

    for(list<int>::iterator it = lst1.begin(); it != lst1.end(); it++) // вставка нового элемента по заданному условию
        if (pred1(*it)) {
            lst1.insert(++it, new_elem);
            it--;
        }

    Y = *max_element(lst2.begin(), lst2.end()); // нахождение максимума
    lst2.erase(remove_if(lst2.begin(), lst2.end(), pred2), lst2.end()); // удаление максимальных элементов

    cout << endl << "Первая последовательность после вставки новых элементов: ";
    for(list<int>::iterator it = lst1.begin(); it != lst1.end(); it++) // вывод
        cout << *it << " ";
    cout << endl;

    cout << "Вторая последовательность после удаления максимальных элементов: ";
    for(list<int>::iterator it = lst2.begin(); it != lst2.end(); it++) // вывод
        cout << *it << " ";
    cout << endl;

    lst1.sort(); // сортировка последовательностей
    lst2.sort();

    cout << endl << "Первая последовательность после сортировки: ";
    for(list<int>::iterator it = lst1.begin(); it != lst1.end(); it++) // вывод
        cout << *it << " ";
    cout << endl;

    cout << "Вторая последовательность после сортировки: ";
    for(list<int>::iterator it = lst2.begin(); it != lst2.end(); it++) // вывод
        cout << *it << " ";
    cout << endl;

    lst1.unique(); // удаление дубликатов
    lst2.unique();

    cout << endl << "Первая последовательность после удаления дубликатов: ";
    for(list<int>::iterator it = lst1.begin(); it != lst1.end(); it++) // вывод
        cout << *it << " ";
    cout << endl;

    cout << "Вторая последовательность после удаления дубликатов: ";
    for(list<int>::iterator it = lst2.begin(); it != lst2.end(); it++) // вывод
        cout << *it << " ";
    cout << endl;

    lst1.merge(lst2); // объединение двух последовательностей в одну

    cout << endl << "Итоговая последовательность: ";
    for(list<int>::iterator it = lst1.begin(); it != lst1.end(); it++)//вывод
        cout << *it << " ";
    cout << endl;

    return 0;
}
