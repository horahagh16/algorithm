#include <iostream>
using namespace std;




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    long long q;
    cin >> n >> q;
    long long que[n];
    long long que3[n];
    que3[0] = 0;
    que3[1] = 0;
    que3[2] = 0;
    long long index = 1;
    for (int i = 0; i < q; ++i) {
        int action;
        cin >> action;
        if (action == 1) {
            long long x;
            cin >> x;
            que[index] = que[index - 1] + x;
            index++;
        } else {
            long long which;
            long long j=0;
            cin >> which >> j;
            cout << que[j+que3[which]] - que[que3[which]] << "\n";
            que3[which]=que3[which]+j;
        }
    }
    return 0;
}