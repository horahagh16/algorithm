#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

unordered_map<int, vector<int>> tree;
const long long MAXN = 1000005;
int s;
int visited[MAXN];

int my_max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int my_min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int dfs(int u, int parent) {
    visited[u] = 1;
    int l = -1, r = -1, res;
    for (int v: tree[u]) {
        if (visited[v] == 1 || v == parent) {
            continue;
        }
        if (v <= u) {
            l = my_max(l, dfs(v, u));
        }
        if (v > u) {
            r = my_max(r, dfs(v, u));
        }
    }
    res = my_min(l, r) + 1;
    s = my_max(s, res);
    return res;
}

int main() {
    int n, root;
    cin >> n >> root;
    if (n != 1) {
        for (int i = 0; i < n - 1; i++) {
            int v, u;
            cin >> v >> u;
            if (tree.find(v) == tree.end()) {
                tree[v] = vector<int>();
            }
            tree[v].push_back(u);
            if (tree.find(u) == tree.end()) {
                tree[u] = vector<int>();
            }
            tree[u].push_back(v);
        }
        dfs(root, -1);
        cout << pow(2, s + 1) - 1 << '\n';
        return 0;
    }
    cout << '1' << '\n';
    return 0;
}
