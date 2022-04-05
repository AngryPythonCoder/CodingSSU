#include <iostream>
#include <cmath>

using namespace std;

struct stack { // стек
    int value;
    stack *next;
};

void push(stack *&head, int x) { // операция добавления в стек
    stack *temp = new stack; // новое звено
    temp->value = x;
    temp->next = head;

    head = temp; // перенос головы
}

int pop(stack *&head) { // операция удаления из стека
    int value = head->value; // сохранение значения
    stack *temp = head; // запоминание головы для удаления
    head = head->next; // перенос головы

    delete temp;
    return value;
} 

void input(stack *&head, int n) { // функция ввода в стек
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(head, x);
    }
}

void print(stack *&head) { // функция вывода из стека
    while (head) {
        cout << pop(head) << " ";
    }
    cout << endl;
}

bool is_prime(int x) { // функция проверки, является ли число простым
    if (x < 2) return false;

    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return false;

    return true;
}

void task(stack *&head, stack *&new_head) { // задача
    while (head) {
        if (!is_prime(head->value)) push(new_head, pop(head)); // записываем в новый стек только не-простые числа
        else pop(head);
    }
}

int main() {
    int n;
    cin >> n;

    stack *head = NULL; // исходный стек
    input(head, n); // ввод

    stack *result = NULL; // конечный стек
    task(head, result); // задача

    print(result); // вывод

    return 0;
}