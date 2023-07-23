#include <bits/stdc++.h>

using namespace std;

const int N = 100005; // maximum number of vertices

vector<int> adj[N]; // adjacency list of the tree
int dist[N]; // distance of each node from the root
vector<int> leaf_dist; // distances of all leaf nodes from the root
double statistic[N]; // distances of all leaf nodes from the root with probability
double sum = 0;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    statistic[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        bool is_leaf = true;
        for (int v: adj[u]) {
            if (dist[v] == -1) { // if v hasn't been visited yet
                statistic[v] = statistic[u] * 1/(dist[u] == 0 ? adj[u].size() : adj[u].size() - 1);

                is_leaf = false;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        if (is_leaf)  // if u is a leaf node
            sum += (double) (dist[u] * statistic[u]);

    }
}

int main() {
    int v; // number of vertices in the tree
    cin >> v;
    for (int i = 1; i < v; i++) {
        int u, w; // u and w are connected by an edge
        cin >> u >> w;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }
    int s = 1; // root node (1 is the root)
    memset(dist, -1, sizeof(dist)); // set all distances to -1
    bfs(s);
    cout << fixed << setprecision(7) << sum << endl;
    return 0;
}
