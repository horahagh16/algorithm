#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int countPermutations(int n) {
    vector<int> nums(n + 1);
    vector<bool> used(n + 1, false);
    int count = 0;

    // Backtracking function to find valid permutations
    function<void(int)> backtrack = [&](int pos) {
        // Base case: all numbers have been placed
        if (pos > n) {
            count++;
            return;
        }

        // Try placing each unused number at the current position
        for (int i = 1; i <= n; i++) {
            if (!used[i] && (i % pos == 0 || pos % i == 0)) {
                nums[pos] = i;
                used[i] = true;
                backtrack(pos + 1);
                used[i] = false;
            }
        }
    };

    backtrack(1);
    return count;
}

int main() {
    int n;
    cin >> n;
    int result = countPermutations(n);
    cout << result << endl;
    return 0;
}
