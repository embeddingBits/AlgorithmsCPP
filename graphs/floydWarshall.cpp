#include <iostream>
using namespace std;

#define MAX 100
#define INF 99999

int dist[MAX][MAX];

void floydWarshall(int V) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

    cout << "\nShortest distances between all pairs:" << endl;
    cout << "\t";
    for (int i = 0; i < V; i++)
        cout << i << "\t";
    cout << endl;

    for (int i = 0; i < V; i++) {
        cout << i << "\t";
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    // Initialize distance matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter each edge (src dest weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    floydWarshall(V);
    return 0;
}
