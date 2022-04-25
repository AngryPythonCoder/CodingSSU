#include <iostream>

using namespace std;

struct list {
    int value;
    list *previous;
    list *next;
};

void push(list *&head, list *&tail, int x) {
    list *temp = new list;
    temp->value = x;

    if (!head) {
        temp->previous = NULL;
        head = temp;
    }
    else {
        tail->next = temp;
        temp->previous = tail;
    }

    temp->next = NULL;
    tail = temp;
}

void insert_after(list *&head, list *&tail, list *&element, int x) {
    list *temp = new list;
    temp->value = x;

    if (element != tail) {
        element->next->previous = temp;
        temp->next = element->next;
    }
    else {
        temp->next = NULL;
        tail = temp;
    }

    element->next = temp;
    temp->previous = element;
}

int get_value(list *&element) {
    return element->value;
}

list* get_previous(list *&element) {
    return element->previous;
}

list* get_next(list *&element) {
    return element->next;
}

void cyclic_shift(list *&head, list *&tail, list *&new_head) {
    head->previous = tail;
    tail->next = head;

    head = new_head;
    tail = new_head->previous;

    head->previous = NULL;
    tail->next = NULL;
}

//=======================================
//тут типо реализация списка кончилась
//=======================================

void input_list(list *&head, list *&tail, int n) {
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(head, tail, x);
    }
}

void print_list(list *&head, list *&tail) {
    list *current = head;

    while (current) {
        cout << get_value(current) << " ";
        current = get_next(current);
    }

    cout << endl;
}

list* first_max(list *&head, list *&tail) {
    list *current = head;
    int maximum = get_value(current);

    while (current != tail) {
        current = get_next(current);
        if (get_value(current) > maximum)
            maximum = get_value(current);
    }

    current = head;
    while (current != tail) {
        current = get_next(current);
        if (get_value(current) == maximum)
            return current;
    }
}

void task(list *&head, list *&tail) {
    list *new_head = first_max(head, tail);

    cyclic_shift(head, tail, new_head);
}

int main() {
    list *head = NULL, *tail = NULL;
    int n;

    cin >> n;

    input_list(head, tail, n);

    task(head, tail);

    print_list(head, tail);

    return 0;
}