#include <bits/stdc++.h>

using namespace std;

string findLongestSubsequence(const string &s1, const string &s2, const string &forbidden) {
    int n1 = s1.length();
    int n2 = s2.length();

    // Initialize the DP table with zeros
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Find the longest common subsequence
    string lcs;
    int i = n1, j = n2;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs.push_back(s1[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());

    // Remove the forbidden subsequence from the longest common subsequence
    size_t pos = lcs.find(forbidden);
    if (pos != string::npos) {
        lcs.erase(pos, 1);
    }

    return lcs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2, forbidden;
    cin >> s1 >> s2 >> forbidden;

    string longestSubsequence = findLongestSubsequence(s1, s2, forbidden);

    int c = longestSubsequence.length();
    while (c != 0) {
        size_t pos = longestSubsequence.find(forbidden);
        if (pos != string::npos) {
            longestSubsequence.erase(pos, 1);
        }
        c--;
    }

    cout << longestSubsequence << endl;

    return 0;
}
