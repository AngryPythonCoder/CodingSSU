#include <iostream>
#include <vector>

using namespace std;

// очередь
struct queue { 
    int value;
    queue *next;
};

// операция добавления в конец очереди
void push(queue *&head, queue *&tail, int x) { 
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

// функция вытаскивания из очереди
int pop(queue *&head, queue *&tail) { 
    int value = head->value; // сохранение значения

    queue *temp = head; // запоминание удаляемого звена
    head = head->next; // перенос головы

    if (!head) tail = NULL; // случай, когда очередь из одного элемента

    delete temp;
    return value;
}

// волновой алгоритм поиска кратчайшего пути
int BFS(vector<vector<int>> &Graph, vector<int> &distance, int x, int y) {
    queue *head = NULL; // создание очереди
    queue *tail = NULL;

    int current = x; // текущий элемент
    distance[current] = 0;
    push(head, tail, current);

    while (head) {
        current = pop(head, tail); // вытаскиваемый первый элемент очереди

        if (current == y) return distance[current]; // если нашли нужный
        
        for (int i = 0; i < Graph[current].size(); i++)
            if (distance[Graph[current][i]] == -1) { // если вершина ещё не посещена
                distance[Graph[current][i]] = distance[current] + 1; // обновляем расстояние от начальной
                push(head, tail, Graph[current][i]); // записываем в очередь
            }
    }
}

int main() {
    int n, m, vertex, x, y;

    vector<vector<int>> Graph; // список смежности
    vector<int> distance; // массив, указывающий, была лишь вершина посещена

    cin >> n >> m; // ввод количества вершин и рёбер

    Graph.resize(n);
    distance.resize(n);

    for (int i = 0; i < m; i++) { // ввод графа
        cin >> x >> y;
        Graph[--x].push_back(--y);
        Graph[y].push_back(x);
    }

    for (int i = 0; i < n; i++) distance[i] = -1; // заполнение базовыми значениями

    int start, end;

    cin >> start >> end; // ввод вершин, между которыми ищется путь

    cout << BFS(Graph, distance, --start, --end) << endl; // вывод ответа

    return 0;
}