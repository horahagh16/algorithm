#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_sum_matrix(int n, int m, vector<vector<int>>& matrix) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Fill the first row and column of the DP table
    dp[0][0] = matrix[0][0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + matrix[i][0];
    }
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j-1] + matrix[0][j];
    }

    // Fill the rest of the DP table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + matrix[i][j];
        }
    }

    return dp[n-1][m-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int max_sum = max_sum_matrix(n, m, matrix);
    cout << max_sum << endl;

    return 0;
}
