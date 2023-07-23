#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> indexes;
std::vector<std::vector<bool>> dp;

void my_print(int row, int col, vector<int> numbers) {
    if (row == 0) {
        return;
    }
    if (col >= numbers[row - 1] && dp[row - 1][col - numbers[row - 1]]) {
        my_print(row - 1, col - numbers[row - 1], numbers);
        indexes.push_back(row);
    } else if (dp[row - 1][col])
        my_print(row - 1, col, numbers);
}

void findIndexes(int target, const std::vector<int> &numbers) {
    int n = numbers.size();

    // Dynamic programming table to store the minimum sum
    std::vector<std::vector<bool>> my_dp(n + 1, std::vector<bool>(3 * target + 1, false));

    // Base case: If target is 0, empty subset is the solution
    for (int i = 0; i < n; i++) {
        my_dp[i][0] = true;
    }
    // Build up the dynamic programming table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2 * target; j++) {
            // If current number is less than or equal to the target, we have two options
            // Either include the number in the subset or exclude it
            my_dp[i][j] = my_dp[i - 1][j] || (j >= numbers[i - 1] && my_dp[i - 1][j - numbers[i - 1]]);
        }
    }
    int sum = 0;
    for (sum = target + 1; sum <= 2 * target; sum++) {
        if (my_dp[n][sum]) {
            break;
        }
    }
    dp = my_dp;
    my_print(n, sum, numbers);
}

int main() {
    int n, target, temp;
    std::cin >> n >> target;
    cin >> temp;
    target -= temp;
    vector<int> numbers(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int a;
        std::cin >> a;
        numbers[i] = a;
    }

    findIndexes(target, numbers);
    if (indexes.empty()) {
    } else {
        std::cout << "0 ";
        for (int index: indexes) {
            std::cout << index << " ";
        }
    }

    return 0;

}