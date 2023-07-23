#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // Pair of (weight, node)

void dijkstra(const vector<vector<pii>> &graph, int start, vector<int> &dist) {
    int n = graph.size();
    dist.assign(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        if (du > dist[u])
            continue;

        for (const auto &neighbor: graph[u]) {
            int v = neighbor.second;
            int weight = neighbor.first;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; ++k) {
        int n, m, p;
        cin >> n >> m >> p;

        int s, g, h;
        cin >> s >> g >> h;

        vector<vector<pii>> graph(n + 1); // 1-indexed graph

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({w, v});
            graph[v].push_back({w, u});
        }

        vector<int> destinations(p);
        for (int i = 0; i < p; i++)
            cin >> destinations[i];

        vector<int> dist_s, dist_g, dist_h;
        dijkstra(graph, s, dist_s);
        dijkstra(graph, g, dist_g);
        dijkstra(graph, h, dist_h);

        vector<int> selected_destinations;
        for (int destination: destinations) {
            int sg = dist_s[g] + dist_g[h] + dist_h[destination];
            int sh = dist_s[h] + dist_h[g] + dist_g[destination];

            if (sg == dist_s[destination] || sh == dist_s[destination])
                selected_destinations.push_back(destination);
        }
        sort(selected_destinations.begin(), selected_destinations.end());

        for (int dest: selected_destinations)
            cout << dest << " ";
        cout << endl;
    }
    return 0;
}
