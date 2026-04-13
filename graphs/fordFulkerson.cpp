#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

#define MAX 100

int capacity[MAX][MAX];
int visited[MAX];
int V;

int dfs(int u, int sink, int flow) {
    if (u == sink) return flow;
    visited[u] = 1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && capacity[u][v] > 0) {
            int bottleneck = dfs(v, sink, min(flow, capacity[u][v]));
            if (bottleneck > 0) {
                capacity[u][v] -= bottleneck;
                capacity[v][u] += bottleneck;
                return bottleneck;
            }
        }
    }
    return 0;
}

int fordFulkerson(int source, int sink) {
    int maxFlow = 0;

    while (true) {
        memset(visited, 0, sizeof(visited));
        int flow = dfs(source, sink, INT_MAX);
        if (flow == 0) break;
        maxFlow += flow;
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

    cout << "\nMaximum Flow (Ford-Fulkerson): " << fordFulkerson(source, sink) << endl;
    return 0;
}
