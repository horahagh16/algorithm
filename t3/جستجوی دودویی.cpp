#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // read matrix
    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // mark reachable W's
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 'W' && !visited[i][j]) {
                // found new W
                q.push(make_pair(i, j));
                visited[i][j] = true;
                bool reachable = false;
                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();
                    if (curr.first == 0 || curr.first == n - 1 || curr.second == 0 || curr.second == m - 1) {
                        // current W is at the edge of the matrix
                        reachable = true;
                    }
                    // check neighbors
                    if (curr.first > 0 && matrix[curr.first - 1][curr.second] == 'W' && !visited[curr.first - 1][curr.second]) {
                        q.push(make_pair(curr.first - 1, curr.second));
                        visited[curr.first - 1][curr.second] = true;
                    }
                    if (curr.first < n - 1 && matrix[curr.first + 1][curr.second] == 'W' && !visited[curr.first + 1][curr.second]) {
                        q.push(make_pair(curr.first + 1, curr.second));
                        visited[curr.first + 1][curr.second] = true;
                    }
                    if (curr.second > 0 && matrix[curr.first][curr.second - 1] == 'W' && !visited[curr.first][curr.second - 1]) {
                        q.push(make_pair(curr.first, curr.second - 1));
                        visited[curr.first][curr.second - 1] = true;
                    }
                    if (curr.second < m - 1 && matrix[curr.first][curr.second + 1] == 'W' && !visited[curr.first][curr.second + 1]) {
                        q.push(make_pair(curr.first, curr.second + 1));
                        visited[curr.first][curr.second + 1] = true;
                    }
                }
                if (reachable) {
                    // mark all visited W's
                    for (int k = 0; k < n; k++) {
                        for (int t = 0; t < m; t++) {
                            if (visited[k][t]) {
                                matrix[k][t] = '1';
                            }
                        }
                    }
                }
                // clear visited
                for (int k = 0; k < n; k++) {
                    for (int t = 0; t < m; t++) {
                        visited[k][t] = false;
                    }
                }
            }
        }
    }

    // print matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1')
                cout << matrix[i][j];
            else
                cout << 0;
        }
        cout << endl;
    }

    return 0;
}