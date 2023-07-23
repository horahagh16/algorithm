#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
    int u, v, w;

    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

const int MAXN = 2005;
int parent[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    int p1 = find(u);
    int p2 = find(v);
    parent[p2] = p1;
}

int mst(int n, vector<vector<int>> &edges, vector<int> &yes, vector<int> &no) {

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int ans = 0;
    int count = 0;

    if (!yes.empty()) {
        merge(yes[0], yes[1]);
        ans += yes[2];
        count += 1;
    }
    for (vector<int> edge: edges) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        if ((!no.empty() && no[0] == u && no[1] == v && no[2] == cost) ||
            (!yes.empty() && yes[0] == u && yes[1] == v && yes[2] == cost)) {
            continue;
        }

        int p1 = find(u);
        int p2 = find(v);

        if (p1 != p2) {
            merge(p1, p2);
            ans += cost;
            count += 1;
        }
    }
    if (count == n - 1) {
        return ans;
    } else {
        return MAXN;
    }
}

void findEdges(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graphEdges;
    vector<int> criticalEdges;
    vector<int> pseudoCriticalEdges;

    for (vector<int> edge: edges) {
        vector<int> graphEdge{edge[0], edge[1], edge[2]};
        graphEdges.push_back(graphEdge);
    }

    sort(edges.begin(), edges.end(),
         [](const vector<int> &x, const vector<int> &y) { return x[2] < y[2]; });

    vector<int> temp;
    int cost = mst(n, edges, temp, temp);

    for (int i = 0; i < graphEdges.size(); i++) {
        int excludedCost = mst(n, edges, temp, graphEdges[i]);
        int includedCost = mst(n, edges, graphEdges[i], temp);
        if (excludedCost > cost) {
            criticalEdges.push_back(i);
        } else if (includedCost == cost) {
            pseudoCriticalEdges.push_back(i);
        }
    }
    for (int i: criticalEdges) {
        cout << i << " ";
    }
    cout << endl;
    for (int i: pseudoCriticalEdges) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    findEdges(n, edges);
    return 0;
}