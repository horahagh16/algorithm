#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int source, destination, weight;
};

vector<int> bellmanFord(vector<Edge> &edges, int n) {
    const int INF = 1e9;
    vector<int> distance(n, INF);
    vector<int> parent(n, -1);
    int lastUpdated;

    distance[0] = 0;

    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        lastUpdated = -1;

        for (const auto &edge: edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;

            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                parent[v] = u;
                lastUpdated = v;
            }
        }
    }

    // Check for negative cycles
    if (lastUpdated != -1) {
        int start = lastUpdated;

        // Find a node that is part of the negative cycle
        for (int i = 0; i < n; i++) {
            start = parent[start];
        }

        vector<int> cycle;
        int current = start;

        // Traverse the negative cycle
        do {
            cycle.push_back(current);
            current = parent[current];
        } while (current != start);

        cycle.push_back(current);
        reverse(cycle.begin(), cycle.end());

        return cycle;
    }

    return {};
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    vector<int> negativeCycle = bellmanFord(edges, n);

    if (negativeCycle.empty()) {
        cout << -1 << endl;
    } else {
        cout << negativeCycle.size() - 1 << endl;
        for (int node: negativeCycle) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
