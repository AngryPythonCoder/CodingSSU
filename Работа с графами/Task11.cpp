#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, m, vertex, x, y;

    vector<vector<int>> Graph; // список смежности

    cin >> n >> m; // ввод количества вершин и рёбер

    Graph.resize(n);

    for (int i = 0; i < m; i++) { // ввод графа
        cin >> x >> y;
        Graph[--x].push_back(--y);
        Graph[y].push_back(x);
    }

    for (int i = 0; i < n; i++) // вывод степеней
        cout << i+1 << ": " << Graph[i].size() << endl;

    return 0;
}