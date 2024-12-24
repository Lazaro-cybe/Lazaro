// Task 2: Breadth-First Search (BFS) - Non-interactive
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int startNode, const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {},
        {2, 3},
        {1, 4, 5},
        {1},
        {2},
        {2}
    };

    cout << "BFS starting from node 1: ";
    bfs(1, graph);
    return 0;
}