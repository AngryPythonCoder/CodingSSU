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
        temp->previous = temp;
        head = temp;
    }
    else {
        tail->next = temp;
        temp->previous = tail;
    }

    temp->next = head;
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

void delete_element(list *&element) {
    element->previous->next = element->next;
    element->next->previous = element->previous;

    delete element;
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
    cout << get_value(current) << " ";

    while (current != tail) {
        current = get_next(current);
        cout << get_value(current) << " ";
    }

    cout << endl;
}

void task(list *&head, list *&tail, int k, int n) {
    list *current = get_next(head);

    for (int j = 0; j < n-1; j++) {
        for (int i = 0; i < k-1; i++)
            current = get_next(current);

        list *previous = get_previous(current);
        delete_element(previous);
    }
}

int main() {
    list *head = NULL, *tail = NULL;
    int n, k;

    cin >> n >> k;

    input_list(head, tail, n);

    task(head, tail, k, n);

    print_list(head, tail);

    return 0;
}