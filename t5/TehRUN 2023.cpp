#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    long start_time;
    long deadline;
    long cost;
};

bool compareTasks(const Task& t1, const Task& t2) {
    return t1.deadline < t2.deadline;
}

long findMaxCost(const vector<Task>& tasks) {
    long n = tasks.size();
    vector<long> dp(n, 0);

    dp[0] = tasks[0].cost;

    for (long i = 1; i < n; i++) {
        long prevMaxCost = 0;
        for (long j = i - 1; j >= 0; j--) {
            if (tasks[j].deadline <= tasks[i].start_time) {
                prevMaxCost = dp[j];
                break;
            }
        }
        dp[i] = max(dp[i - 1], prevMaxCost + tasks[i].cost);
    }

    return dp[n - 1];
}

int main() {
    long n, m;
    cin >> n >> m;

    vector<Task> tasks(m);
    for (long i = 0; i < m; i++) {
        cin >> tasks[i].start_time >> tasks[i].deadline >> tasks[i].cost;
    }

    sort(tasks.begin(), tasks.end(), compareTasks);

    long maxCost = findMaxCost(tasks);

    cout << maxCost << endl;

    return 0;
}
