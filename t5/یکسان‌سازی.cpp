#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int N;
    string str1, str2;

    // Read the input
    cin >> N >> str1 >> str2;

    int cost = 0;

    for (int i = 0; i < N; i++) {
        if (str1[i] != str2[i]) {
            // If the bits are different, calculate the cost
            if (i + 1 < N && str1[i] != str1[i + 1] && str1[i + 1] != str2[i + 1]) {
                // Swap the current bit and the next bit
                swap(str1[i], str1[i + 1]);
                cost += abs(i - (i + 1));
            } else {
                // Flip the current bit
                str1[i] = (str1[i] == '0') ? '1' : '0';
                cost++;
            }
        }
    }

    cout << cost << endl;

    return 0;
}
