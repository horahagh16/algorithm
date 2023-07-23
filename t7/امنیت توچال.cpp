#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long mergeAndCount(vector<long long>& numbers, long long left, long long mid, long long right) {
    long long count = 0;

    // Count the pairs with the condition: numbers[i] > 2 * numbers[j]
    long long i = left;
    long long j = mid + 1;

    while (i <= mid && j <= right) {
        if (numbers[i] > 2 * numbers[j]) {
            count += mid - i + 1;  // Increment count by the number of elements from i to mid
            j++;
        } else {
            i++;
        }
    }

    // Merge the two sorted halves
    inplace_merge(numbers.begin() + left, numbers.begin() + mid + 1, numbers.begin() + right + 1);

    return count;
}

long long mergeSortAndCount(vector<long long>& numbers, long long left, long long right) {
    long long count = 0;

    if (left < right) {
        long long mid = (left + right) / 2;

        // Recursive calls to sort and count pairs
        count += mergeSortAndCount(numbers, left, mid);
        count += mergeSortAndCount(numbers, mid + 1, right);

        // Merge the two sorted halves and count pairs
        count += mergeAndCount(numbers, left, mid, right);
    }

    return count;
}

long long countPairs(vector<long long>& numbers) {
    return mergeSortAndCount(numbers, 0, numbers.size() - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;

    vector<long long> numbers(n);
    for (long long i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    long long pairCount = countPairs(numbers);
    cout << pairCount << endl;

    return 0;
}
