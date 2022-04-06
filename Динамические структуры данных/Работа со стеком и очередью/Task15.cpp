#include <iostream>

using namespace std;

int first, last, new_element; 
// глобальные переменные, хранящие значения
// первого, последнего и нового элемента

struct queue { // очередь
    int value;
    queue *next;
};

void push(queue *&head, queue *&tail, int x) { // операция добавления в конец очереди
    queue *temp = new queue; // новое звено
    temp->value = x;
    temp->next = NULL;

    if (!head && !tail) // случай пустой очереди
        head = tail = temp;

    else { // переопределение хвоста
        tail->next = temp; 
        tail = temp;
    }
}

int pop(queue *&head, queue *&tail) { // функция вытаскивания из очереди
    int value = head->value; // сохранение значения

    queue *temp = head; // запоминание удаляемого звена
    head = head->next; // перенос головы

    if (!head) tail = NULL; // случай, когда очередь из одного элемента

    delete temp;
    return value;
}

void input(queue *&head, queue *&tail, int n) { // функция ввода в очередь
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(head, tail, x);
    }
}

void print(queue *&head, queue *&tail) { // функция вывода из очереди
    while (head)
        cout << pop(head, tail) << " ";

    cout << endl;
}

void task(queue *&head, queue *&tail, queue *&res_head, queue *&res_tail) { // задача
    while (head) {
        int x = pop(head, tail); // вытаскиваем значение из исходнй очереди
        push(res_head, res_tail, x); // пишем в новую

        if (x == first || x == last) // случай, когда надо вставить новый элемент
            push(res_head, res_tail, new_element);
    }
}

int main() {
    int n;
    cin >> n >> new_element;

    queue *head = NULL; // исходная очередь
    queue *tail = NULL;
    input(head, tail, n); // ввод

    first = head->value; // занос значений первого и последнего элемента
    last = tail->value;

    queue *res_head = NULL; // результирующая очередь
    queue *res_tail = NULL;
    task(head, tail, res_head, res_tail); // решение задачи

    print(res_head, res_tail); // вывод

    return 0;
}