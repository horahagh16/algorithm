#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100500];

int shortest_cycle(int n) {
    int answer = INT_MAX;
    vector<int> cycle;
    for (int i = 0; i < n; i++) {
        vector<int> dist(n, (int) (1e9));
        vector<int> par(n, -1);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int child: graph[x]) {
                if (dist[child] == (int) (1e9)) {
                    dist[child] = 1 + dist[x];
                    par[child] = x;
                    q.push(child);
                } else if (par[x] != child and par[child] != x) {
                    if (answer > dist[x] + dist[child] + 1) {
                        answer = dist[x] + dist[child] + 1;
                        cycle.clear();
                        int curr = x;
                        while (curr != i) {
                            cycle.push_back(curr);
                            curr = par[curr];
                        }
                        cycle.push_back(i);
                        reverse(cycle.begin(), cycle.end());
                        curr = child;
                        while (curr != i) {
                            cycle.push_back(curr);
                            curr = par[curr];
                        }
                    }
                }
            }
        }
    }

    if (answer == INT_MAX)
        return -1;

    cout << answer << endl;
    for (int i: cycle) {
        cout << i << " ";
    }
    cout << cycle[0];

    return answer;
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    shortest_cycle(n);
    return 0;
}
