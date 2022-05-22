#include <iostream>

using namespace std;

template <typename T>
struct stack { // стек
    T value;
    stack *next;
};

template <typename T>
void push(stack<T> *&head, T value) { // операция добавления в стек
    stack<T> *temp = new stack<T>; // новое звено
    temp->value = value;
    temp->next = head;

    head = temp; // перенос головы
}

template <typename T>
T pop(stack<T> *&head) { // операция удаления из стека
    T value = head->value; // сохранение значения
    stack<T> *temp = head; // запоминание головы для удаления
    head = head->next; // перенос головы

    delete temp;
    return value;
}

template <typename T>
struct queue { // очередь
    T value;
    queue *next;
};

template <typename T>
void push(queue<T> *&head, queue<T> *&tail, T x) { // операция добавления в конец очереди
    queue<T> *temp = new queue<T>; // новое звено
    temp->value = x;
    temp->next = NULL;

    if (!head && !tail) // случай пустой очереди
        head = tail = temp;

    else { // переопределение хвоста
        tail->next = temp; 
        tail = temp;
    }
}

template <typename T>
T pop(queue<T> *&head, queue<T> *&tail) { // функция вытаскивания из очереди
    T value = head->value; // сохранение значения

    queue<T> *temp = head; // запоминание удаляемого звена
    head = head->next; // перенос головы

    if (!head) tail = NULL; // случай, когда очередь из одного элемента

    delete temp;
    return value;
}

void write_expression(queue<string> *&expression_head, queue<string> *&expression_tail, string input) { // записываем выражение в очередь
    input += ' '; // терминальный пробел
    int left = 0, right; // границы

    while (left < input.length()) {
        right = input.find_first_of(' ', left);
        push(expression_head, expression_tail, input.substr(left, right-left)); // записываем в очередь операнд или операцию

        left = right+1;
    }
}

bool is_operation(string s) { 
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

int make_operation(int a, int b, string operation) { // выполнение операции
    if (operation == "+") return a+b;
    else if (operation == "-") return a-b;
    else if (operation == "*") return a*b;
    else return a/b; // так как работаем с int'ами, то деление целочисленное
}

int calculate_answer(queue<string> *&expression_head, queue<string> *&expression_tail, stack<int> *&operands) { // функция подсчёта
    while (expression_head) {
        string something = pop(expression_head, expression_tail);

        if (is_operation(something)) { // если вытащили из очереди операцию
            int second = pop(operands); // достаём два последних операнда
            int first = pop(operands); // из отдельного стека

            push(operands, make_operation(first, second, something)); // подсчитываем операцию и записываем обратно
        } 
        else {
            push(operands, stoi(something)); // иначе записываем в стек операндов
        }
    }
    return pop(operands);
}

int main() {
    string input;
    bool console = false; // ввод через консоль

    if (console) getline(cin, input);
    //"+ 5 / * 30 4 - 19 2"
    else input = "12 14 13 - * 15 + 2 /";

    // надо заметить, что программа подсчитывает многозначные числа
    // но, поэтому, все операции и числа должны быть разделены пробелами (одиночными)

    queue<string> *expression_head = NULL; // очередь для хранения выражения
    queue<string> *expression_tail = NULL; // 
    write_expression(expression_head, expression_tail, input); // запись

    stack<int> *operands = NULL; // стек для операндов
    cout << calculate_answer(expression_head, expression_tail, operands) << endl; // подсчёт и вывод

    return 0;
}