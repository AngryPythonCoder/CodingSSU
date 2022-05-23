#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    }

    for (int i = 0; i < n; i++) used[i] = false; // заполнение базовыми значениями

    cin >> x >> y; // ввод нового ребра

    if (find(Graph[x-1].begin(), Graph[x-1].end(), y-1) == Graph[x-1].end()) Graph[x-1].push_back(y-1); // вставляем ребро
    else cout << "Already exists" << endl; // если ребро существует

    return 0;
}