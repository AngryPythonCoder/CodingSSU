#include <iostream>
#include <vector>

using namespace std;

// функция проверки связности
bool is_connected(vector<bool> &used) { 
    bool flag = true;

    for (int i = 0; i < used.size(); i++)
        flag &= used[i];

    return flag;
}

// обход в глубину
void DFS(vector<vector<int>> &Graph, vector<bool> &used, int x) { 
    used[x] = true;

    for (int i = 0; i < Graph[x].size(); i++)
        if (!used[Graph[x][i]])
            DFS(Graph, used, Graph[x][i]);
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

    DFS(Graph, used, 0);

    if (is_connected(used)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}