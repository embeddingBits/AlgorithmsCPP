#include <bits/stdc++.h>
using namespace std;

#define MAX_EDGE 100
#define MAX_NODES 100
#define INF INT_MAX

struct Edge {
      int src, desc, weight;
};

Edge edges[MAX_EDGE];
int dist[MAX_NODES];

void bellmanFord(int V, int E, int src)
{
      for (int i = 0; i < V; i++) {
            dist[i] = INF;
      }
      dist[src] = 0;

      for (int i = 1; i <= V - 1; i++) {
            for (int j = 0; j < E; j++) {
                  int u = edges[j].src;
                  int v = edges[j].desc;
                  int w = edges[j].weight;
                  if (dist[u] != INF && dist[u] + w < dist[v])
                        dist[v] = dist[u] + w;
            }
      }

      for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].desc;
            int w = edges[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                  cout << "Negative cycle detected" << endl;
                  return;
            }
      }

      cout << "Vertex Distance from Source" << src << endl;
      for (int i = 0; i < V; i++) {
            if (dist[i] == INF)
                  cout << "\tINF" << " ";
            else 
                  cout << dist[i] << " ";
      }
}

int main()
{
      int v, e, src;

      cin >> v >> e >> src;

      for (int i = 0; i < e; i++) {
            cin >> edges[i].src >> edges[i].desc >> edges[i].weight;
      }

      bellmanFord(v, e, src);
      return 0;
}
