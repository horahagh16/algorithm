#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end()); // sort tasks by start time
    map<pair<int, int>, int> checker;
    for (const auto &elem: tasks) {
        if (elem.first == elem.second)
            ++checker[elem];
    }

    for (const auto &elem: checker) {
        if (elem.second > m) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // stores ongoing tasks with their deadlines
    int cur_time = 0; // current time
    for (int i = 0; i < n; i++) {
        int start = tasks[i].first;
        int deadline = tasks[i].second;

        // remove finished tasks from the priority queue
        while (!pq.empty() && pq.top().first <= start) {
            pq.pop();
        }

        if (pq.size() == m) {
            // if there are no resources available, try to preempt an ongoing task
            auto [end_time, orig_deadline] = pq.top();
            if (end_time > deadline) {
                cout << "NO\n";
                return 0;
            }
            pq.pop();
            pq.push({max(cur_time, start) + deadline - start, orig_deadline});
        } else {
            pq.push({max(cur_time, start) + deadline - start, deadline});
        }
        cur_time = max(cur_time, start);
    }

    cout << "YES\n";
    return 0;
}
