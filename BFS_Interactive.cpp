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
// Extended BFS to explore disconnected components
void bfsDisconnected(const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    for (int startNode = 1; startNode < graph.size(); ++startNode) {
        if (!visited[startNode]) {
            cout << "BFS starting from node " << startNode << ": ";
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
            cout << endl;
        }
    }
}

// Find shortest path from a starting node using BFS
void shortestPath(int startNode, const vector<vector<int>>& graph) {
    vector<int> distance(graph.size(), -1);
    queue<int> q;

    distance[startNode] = 0;
    q.push(startNode);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }

    cout << "Shortest distances from node " << startNode << ":" << endl;
    for (int i = 1; i < distance.size(); ++i) {
        cout << "Node " << i << ": " 
             << (distance[i] == -1 ? "Not reachable" : to_string(distance[i])) << endl;
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

       // Input validation for edges
        if (u < 1 || u > nodes || v < 1 || v > nodes) {
            cout << "Invalid edge: (" << u << ", " << v << "). Skipping this edge." << endl;
            continue;
                 }   
        graph[u].push_back(v);
        graph[v].push_back(u); // Remove this line if the graph is directed
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    // Input validation for the starting node
    if (startNode < 1 || startNode > nodes) {
        cout << "Invalid starting node. It should be in range [1, " << nodes << "]." << endl;
        return 1;
    }
    
    // Perform BFS from the starting node
    cout << "BFS starting from node " << startNode << ": ";
    bfs(startNode, graph);
    cout << endl;

    cout << "BFS starting from node " << startNode << ": ";
    bfs(startNode, graph);
    return 0;
}
