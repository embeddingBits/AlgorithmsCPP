#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

#define MAX 100

int capacity[MAX][MAX];
int parent[MAX];
int V;

bool bfs(int source, int sink) {
    bool visited[MAX];
    memset(visited, false, sizeof(visited));

    int queue[MAX];
    int front = 0, back = 0;

    queue[back++] = source;
    visited[source] = true;
    parent[source] = -1;

    while (front < back) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && capacity[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                if (v == sink) return true;
                queue[back++] = v;
            }
        }
    }
    return false;
}

int edmondsKarp(int source, int sink) {
    int maxFlow = 0;

    while (bfs(source, sink)) {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, capacity[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            capacity[u][v] -= pathFlow;
            capacity[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int E, source, sink;

    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    memset(capacity, 0, sizeof(capacity));

    cout << "Enter each edge (src dest capacity):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, c;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v >> c;
        capacity[u][v] = c;
    }

    cout << "Enter source vertex: ";
    cin >> source;
    cout << "Enter sink vertex: ";
    cin >> sink;

    cout << "\nMaximum Flow (Edmonds-Karp): " << edmondsKarp(source, sink) << endl;
    return 0;
}
