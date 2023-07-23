#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int u, v, w;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> graph(n + 1);  // 1-based indexing
    vector<int> distances(n + 1, INF);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({u, v, w});
    }

    distances[k] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > distances[u])
            continue;

        for (const Edge& edge : graph[u]) {
            int v = edge.v;
            int w = edge.w;

            if (dist + w < distances[v]) {
                distances[v] = dist + w;
                pq.push({dist + w, v});
            }
        }
    }

    int maxDistance = 0;
    for (int i = 1; i <= n; i++) {
        if (distances[i] == INF) {
            cout << -1 << endl;
            return 0;
        }
        maxDistance = max(maxDistance, distances[i]);
    }

    cout << maxDistance << endl;

    return 0;
}
