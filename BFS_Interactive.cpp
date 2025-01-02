// Task 2: Breadth-First Search (BFS) - Interactive
#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
    int nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    vector<vector<int>> graph(nodes + 1);

    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the edges (node1 node2):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Remove this line if the graph is directed
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    cout << "BFS starting from node " << startNode << ": ";
    bfs(startNode, graph);
    return 0;
}
