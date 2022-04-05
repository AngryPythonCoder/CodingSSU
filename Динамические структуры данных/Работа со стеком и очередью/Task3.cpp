#include <iostream>

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

void task(stack *&head, stack *&new_head) { // функция, решающая задачу
    bool flag = true;
    while (head) {
        if (flag && (head->value % 2 == 0)) { // перебор идёт с конца, поэтому 
            flag = false;                     // первым встретится последний чётный элемент
            push(new_head, 0);
        }

        push(new_head, pop(head));
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