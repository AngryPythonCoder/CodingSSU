#include <iostream>
#include <vector>

using namespace std;

// функция, помечающая все вершины, смежные с заданной
void mark_adjacent(vector<vector<int>> &Graph, vector<bool> &used, int vertex) {
    for (int i = 0; i < Graph[vertex].size(); i++) // перебор смежных вершин
        used[Graph[vertex][i]] = true;
}

int main() {
    int n, m, vertex, x, y;

    vector<vector<int>> Graph; // список смежности
    vector<bool> used; // массив, указывающий, была лишь вершина посещена

    cin >> n >> m; // ввод количества вершин и рёбер

    Graph.resize(n);
    used.resize(n);

    for (int i = 0; i < m; i++) { // ввод графа
        cin >> x >> y;
        Graph[--x].push_back(--y);
        Graph[y].push_back(x);
    }

    for (int i = 0; i < n; i++) used[i] = false; // заполнение базовыми значениями

    cin >> vertex; // ввод вершины

    mark_adjacent(Graph, used, --vertex); // отметка всех смежных

    for (int i = 0; i < n; i++) // вывод несмежных
        if (!used[i]) cout << i+1 << " ";

    return 0;
}