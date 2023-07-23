#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, temp;
    cin >> n;
    temp = n;

    int a[n], b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        tasks[i].first = a[i];
        tasks[i].second = b[i];
    }
    map<pair<int, int>, int> checker;
    for (const auto &elem: tasks) {
        if (elem.first == elem.second)
            ++checker[elem];
    }
    for (const auto &elem: checker) {
        if (elem.second > 1) {
            temp--;
        }
    }
    if (temp == n) {
        cout << temp << '\n';
        return 0;
    }
    // Sorting second array in descending order based on frequency
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[b[i]]++;
    }

    vector<pair<int, int>> freq_pairsB;
    for (auto f: freq) {
        freq_pairsB.emplace_back(f.second, f.first);
    }

    sort(freq_pairsB.rbegin(), freq_pairsB.rend());

    //for A
    unordered_map<int, int> freqA;
    for (int i = 0; i < n; i++) {
        freqA[a[i]]++;
    }

    vector<pair<int, int>> freq_pairsA;
    for (auto f: freqA) {
        freq_pairsA.emplace_back(f.second, f.first);
    }

    sort(freq_pairsA.rbegin(), freq_pairsA.rend());

    // Finding maximum number of unique pairs
    int ans = 0;
    int ans2 = 0;
    /* for (auto f: freq_pairsA) {
         int c = f.first;
         for (auto p:freq_pairsB) {
             if (c==0)
                 break;
             if (p.first>0){
                 f.first--;
                 p.first--;
                 ans++;
                 c--;
             }
         }
     }*/
    for (auto f: freq_pairsA) {
        int c = f.first;
        for (int i = 0; i < freq_pairsB.size(); ++i) {
            if (c == 0)
                break;
            if (freq_pairsB[i].first > 0) {
                f.first--;
                --freq_pairsB[i].first;
                ans2++;
                c--;
            }
        }

    }
    cout << ans2 << endl;

    return 0;
}
